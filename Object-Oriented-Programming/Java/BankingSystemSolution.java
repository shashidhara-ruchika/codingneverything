import java.util.*;
import java.util.stream.Collectors;

public class BankingSystemSolution {

    String[] solution(String[][] queries) {

        List<String> result = new ArrayList<>();
        // Arrays.sort(queries, Comparator.comparingInt(a -> Integer.parseInt(a[1])));

        BankingSystem bs = new BankingSystem();

        for (String[] query : queries) {
            switch (query[0]) {
                case "CREATE_ACCOUNT": {
                    Boolean createAccountResult = bs.createAccount(query[2]);
                    result.add(createAccountResult.toString());
                    break;
                }
                case "DEPOSIT": {
                    Integer depositResult = bs.deposit(query[2], Integer.parseInt(query[3]));
                    result.add(depositResult == null ? "" : depositResult.toString());
                    break;
                }
                case "PAY": {
                    Integer payResult = bs.pay(query[2], Integer.parseInt(query[3]));
                    result.add(payResult == null ? "" : payResult.toString());
                    break;
                }
                case "TOP_ACTIVITY": {
                    List<Account> topNAccounts = bs.getTopNSortedAccounts(Integer.parseInt(query[2]));
                    if (topNAccounts.isEmpty()) {
                        result.add("");
                    } else {
                        List<String> accountsString = topNAccounts.stream()
                                .map(a -> a.printAccount())
                                .collect(Collectors.toList());
                        result.add(String.join(", ", accountsString));
                    }
                    break;
                }
                case "TRANSFER": {
                    String transferResult = bs.transfer(Long.parseLong(query[1]), query[2], query[3],
                            Integer.parseInt(query[4]));
                    result.add(transferResult == null ? "" : transferResult);
                    break;
                }
                case "ACCEPT_TRANSFER": {
                    Boolean acceptTransferResult = bs.acceptTransfer(Long.parseLong(query[1]), query[2], query[3]);
                    result.add(acceptTransferResult.toString());
                    break;
                }
            }
        }

        return result.stream().toArray(String[]::new);
    }

    class BankingSystem {
        Map<String, Account> bankAccounts;
        Map<String, Transfer> transfers;
        Long DAY;

        BankingSystem() {
            bankAccounts = new HashMap<>();
            transfers = new HashMap<>();
            DAY = 86400000L;
        }

        public Account getAccount(String accountId) {
            return bankAccounts.get(accountId);
        }

        public Boolean createAccount(String accountId) {
            if (getAccount(accountId) != null) {
                return false;
            }
            bankAccounts.put(accountId, new Account(accountId));
            return true;
        }

        public Integer deposit(String accountId, Integer amount) {
            Account account = getAccount(accountId);
            if (account == null) {
                return null;
            }
            account.deposit(amount);
            account.addTransactionAmount(amount);

            return account.amount;
        }

        public Integer pay(String accountId, Integer amount) {

            Account account = getAccount(accountId);
            if (account == null) {
                return null;
            }

            Boolean hasWithdrawn = account.withdraw(amount);
            if (!hasWithdrawn) {
                return null;
            }
            account.addTransactionAmount(amount);

            return account.amount;
        }

        public List<Account> getTopNSortedAccounts(int n) {
            List<Account> accounts = bankAccounts.values().stream().collect(Collectors.toList());
            Collections.sort(accounts);

            List<Account> topNAccounts = new ArrayList<>();

            for (int i = 0; i < n && i < accounts.size(); i++) {
                topNAccounts.add(accounts.get(i));
            }
            return topNAccounts;

        }

        public Boolean isInvalidInitiateTransfer(Long createdTimestamp, String sourceId, String destinationId, Integer amount) {
            return sourceId.equals(destinationId) || !bankAccounts.containsKey(sourceId)
                    || !bankAccounts.containsKey(destinationId);
        }

        public String transfer(Long createdTimestamp, String sourceId, String destinationId, Integer amount) {
            if(isInvalidInitiateTransfer(createdTimestamp, sourceId, destinationId, amount)) {
                return null;
            }

            Account sourceAccount = getAccount(sourceId);
            if (sourceAccount == null) {
                return null;
            }

            Boolean hasWithdrawn = sourceAccount.withdraw(amount);
            if (!hasWithdrawn) {
                return null;
            }

            Transfer transfer = new Transfer(createdTimestamp + DAY, bankAccounts.get(sourceId),
                    bankAccounts.get(destinationId), amount);
            String transferId = "transfer" + Integer.valueOf(transfers.size() + 1).toString();
            transfers.put(transferId, transfer);
            return transferId;
            
        }

        public Boolean isInvalidAcceptTransfer(Long timestamp, String destinationId, Transfer transfer) {
            return transfer == null || !destinationId.equals(transfer.destination.accountId) || transfer.isProcessed;
        }

        public Boolean acceptTransfer(Long timestamp, String destinationId, String transferId) {

            Transfer transfer = transfers.get(transferId);
            if (isInvalidAcceptTransfer(timestamp, destinationId, transfer)) {
                return false;
            }

            Account sourceAccount = transfer.source;
            Account destinationAccount = transfer.destination;
            
            if (timestamp > transfer.expirationTime) {
                sourceAccount.deposit(transfer.amount);
                transfer.isProcessed = true;
                return false;
            }

            destinationAccount.deposit(transfer.amount); 

            transfer.isProcessed = true;
            sourceAccount.addTransactionAmount(transfer.amount);
            destinationAccount.addTransactionAmount(transfer.amount);
            return true;
        }
    }

    class Transfer {
        Long expirationTime;
        Account source;
        Account destination;
        Boolean isProcessed;
        Integer amount;

        Transfer(Long time, Account s, Account d, Integer a) {
            this.expirationTime = time;
            this.source = s;
            this.destination = d;
            isProcessed = false;
            this.amount = a;
        }

        @Override
        public String toString() {
            return new StringBuilder()
                .append("Transfer{")
                .append("expirationTime=")
                .append(expirationTime)
                .append(", source=")
                .append(source)
                .append(", destination=")
                .append(destination)
                .append(", isProcessed=")
                .append(isProcessed)
                .append(", amount=")
                .append(amount)
                .append("}")
                .toString();
        }
    }

    class Account implements Comparable<Account> {
        String accountId;
        Integer amount;
        Integer transactionAmount;

        Account(String accountId) {
            this.accountId = accountId;
            this.amount = 0;
            this.transactionAmount = 0;
        }

        @Override
        public int compareTo(Account otherAccount) {
            if (this.transactionAmount.equals(otherAccount.transactionAmount)) {
                return this.accountId.compareTo(otherAccount.accountId);
            }
            return otherAccount.transactionAmount.compareTo(this.transactionAmount);
        }

        @Override
        public String toString() {
            return new StringBuilder()
                .append("Account{")
                .append("accountId='")
                .append(accountId)
                .append("', amount=")
                .append(amount)
                .append(", transactionAmount=")
                .append(transactionAmount)
                .append("}")
                .toString();
        }

        public String printAccount() {
            return new StringBuilder()
                .append(accountId)
                .append("(")
                .append(amount)
                .append(")")
                .toString();
        }

        public void deposit(Integer amount) {
            this.amount += amount;
        }

        public Boolean withdraw(Integer amount) {
            if (amount > this.amount) {
                return false;
            }
            this.amount -= amount;
            return true;
        }

        public void addTransactionAmount(Integer amount) {
            this.transactionAmount += amount;
        }
    }

}
