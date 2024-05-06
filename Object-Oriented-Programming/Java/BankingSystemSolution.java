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
                    if (depositResult == null) {
                        result.add("");
                    } else {
                        result.add(depositResult.toString());
                    }
                    break;
                }
                case "PAY": {
                    Integer payResult = bs.pay(query[2], Integer.parseInt(query[3]));
                    if (payResult == null) {
                        result.add("");
                    } else {
                        result.add(payResult.toString());
                    }
                    break;
                }

                case "TOP_ACTIVITY": {
                    List<Account> topNAccounts = bs.getTopNSortedAccounts(Integer.parseInt(query[2]));
                    if (topNAccounts.isEmpty()) {
                        result.add("");
                    } else {
                        List<String> accountsString = topNAccounts.stream()
                                .map(a -> a.accountId + "(" + a.transactionAmount + ")")
                                .collect(Collectors.toList());
                        result.add(String.join(", ", accountsString));
                    }
                    break;
                }

                case "TRANSFER": {
                    String transferResult = bs.transfer(Long.parseLong(query[1]), query[2], query[3],
                            Integer.parseInt(query[4]));
                    if (transferResult == null) {
                        result.add("");
                    } else {
                        result.add(transferResult);
                    }

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

        public Integer depositAmount(String accountId, Integer amount) {
            Account account = getAccount(accountId);
            if (account == null) {
                return null;
            }
            account.amount = account.amount + amount;
            return account.amount;
        }

        public Integer addTransactionAmount(String accountId, Integer amount) {
            Account account = getAccount(accountId);
            if (account == null) {
                return null;
            }
            account.transactionAmount = account.transactionAmount + amount;
            return account.transactionAmount;
        }

        public Integer deposit(String accountId, Integer amount) {
            Integer depositResult = depositAmount(accountId, amount);

            if (depositResult == null) {
                return null;
            }

            addTransactionAmount(accountId, amount);
            return depositResult;
        }

        public Integer withdrawAmount(String accountId, Integer amount) {
            Account account = getAccount(accountId);
            if (account == null) {
                return null;
            }

            if (account.amount < amount) {
                return null;
            }
            account.amount = account.amount - amount;
            return account.amount;
        }

        public Integer pay(String accountId, Integer amount) {

            Integer payResult = withdrawAmount(accountId, amount);
            if (payResult == null) {
                return null;
            }

            addTransactionAmount(accountId, amount);

            return payResult;
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

        public String transfer(Long createdTimestamp, String sourceId, String destinationId, Integer amount) {
            if (sourceId.equals(destinationId) || !bankAccounts.containsKey(sourceId)
                    || !bankAccounts.containsKey(destinationId)) {
                return null;
            }
            if (bankAccounts.get(sourceId).amount < amount) {
                return null;
            } else {
                Integer payResult = withdrawAmount(sourceId, amount);
                if (payResult == null) {
                    return null;
                }
                Transfer transfer = new Transfer(createdTimestamp + DAY, bankAccounts.get(sourceId),
                        bankAccounts.get(destinationId), amount);
                String transferId = "transfer" + Integer.valueOf(transfers.size() + 1).toString();
                transfers.put(transferId, transfer);
                return transferId;
            }
        }

        public Boolean isValidTransfer(Long timestamp, String destinationId, Transfer transfer) {

            if (!destinationId.equals(transfer.destination.accountId)) {
                return false;
            }
            if (transfer.isProcessed) {
                return false;
            }
            if (timestamp > transfer.expirationTime) {
                return false;
            }

            return true;
        }

        public Boolean acceptTransfer(Long timestamp, String destinationId, String transferId) {

            if (!transfers.containsKey(transferId)) {
                return false;
            }
            
            Transfer transfer = transfers.get(transferId);
            if (transfer.isProcessed) {
                return false;
            }

            if (!destinationId.equals(transfer.destination.accountId)) {
                return false;
            }
            
            if (timestamp > transfer.expirationTime) {
                depositAmount(transfer.source.accountId, transfer.amount);
                transfer.isProcessed = true;
                return false;
            }

            
            Integer depositResult = depositAmount(transfer.destination.accountId, transfer.amount);
            if (depositResult == null) {
                depositAmount(transfer.source.accountId, transfer.amount);
                transfer.isProcessed = true;
                return false;
            }

            transfer.isProcessed = true;
            addTransactionAmount(transfer.source.accountId, transfer.amount);
            addTransactionAmount(transfer.destination.accountId, transfer.amount);
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
    }

}
