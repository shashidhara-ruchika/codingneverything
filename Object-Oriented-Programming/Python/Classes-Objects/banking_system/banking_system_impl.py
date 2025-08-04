from banking_system import BankingSystem
import heapq

class Transaction:

    def __init__(self, source_account_id: str, target_account_id: str, timestamp: int, amount: int, id: str):
        self.id = id
        self.source_account_id = source_account_id
        self.target_account_id = target_account_id
        self.timestamp = timestamp
        self.success = True
        self.amount = amount
    
    def falied(self) -> None:
        self.set_success = False

        
        
class Account:
    def __init__(self, account_id: str, created_timestamp: int):
        self.account_id = account_id
        self.created_timestamp = created_timestamp
        self.amount = 0
        self.outgoing_transactions = dict()
        self.incoming_transactions = dict()
        
    def deposit(self, amount: int, timestamp: int, transaction_id: str) -> bool:
        if amount < 0:
            return False
        else:
            t = Transaction("own", self.account_id, timestamp, amount, transaction_id)
            self.incoming_transactions[t.id] = t
            self.amount += amount
            return True
            
    def can_withdraw(self, amount: int) -> bool:
        if amount < 0:
            return False
        elif amount > self.amount:
            return False
        else:
            return True
            
    def withdraw(self, amount: int, timestamp: int, transaction_id: str) -> bool:
        if not self.can_withdraw(amount):
            return False
        else:
            t = Transaction("own", self.account_id, timestamp, amount, transaction_id)
            self.outgoing_transactions[t.id] = t
            self.amount -= amount
            return True

    def get_total_outgoing_transactions_amount(self) -> int:
        trans = self.outgoing_transactions.values()
        total = 0
        for tran in trans:
            total += tran.amount
        return total
        
class Payment:
    
    def __init__(self, account_id : str, amount: int, timestamp: int, id: str):
        self.id = id
        self.amount = amount 
        self.account_id = account_id
        self.timestamp = timestamp   

    def __lt__(self, other: 'Payment') -> bool:
        return self.timestamp < other.timestamp or (self.timestamp == other.timestamp and self.id < other.id)

    

class BankingSystemImpl(BankingSystem):

    _next_transaction_id = 1
    _next_payment_id = 1

    def __init__(self):
        self.accounts = dict()
        self.transactions = dict()
        self.sch_payments_timestamps = []
        self.sch_payments = dict()

    def create_account(self, timestamp: int, account_id: str) -> bool:
        if account_id not in self.accounts:
            a = Account(account_id, timestamp)
            self.accounts[account_id] = a
            return True
        else:
            return False
        
    def deposit(self, timestamp: int, account_id: str, amount: int) -> int | None:
        self._process_scheduled_payments(timestamp)
        if account_id not in self.accounts:
            return None
        else:
            a = self.accounts[account_id]
            transaction_id = "deposit" + str(self._next_transaction_id)
            self._next_transaction_id += 1
            is_success = a.deposit(amount, timestamp, transaction_id)
            if is_success:
                return a.amount
            else:
                return None
            
        
    def transfer(self, timestamp: int, source_account_id: str, target_account_id: str, amount: int) -> int | None:
        self._process_scheduled_payments(timestamp)
        if source_account_id not in self.accounts:
            return None
        if target_account_id not in self.accounts:
            return None
        if source_account_id == target_account_id:
            return None
        s = self.accounts[source_account_id]
        t = self.accounts[target_account_id]
        
        if not s.can_withdraw(amount):
            return None
        
        transaction_id = "transfer" + str(self._next_transaction_id)
        s.withdraw(amount, timestamp, transaction_id)
        t.deposit(amount, timestamp, transaction_id)
        self._next_transaction_id += 1
        
        return s.amount

    def top_spenders(self, timestamp: int, n: int) -> list[str]:
        self._process_scheduled_payments(timestamp)
        spenders = dict()
        for account_id, account in self.accounts.items():
            spenders[account_id] = account.get_total_outgoing_transactions_amount()
        top_spenders_list = sorted(spenders.items(), key= lambda item: (-item[1], item[0]) )
        
        top = []
        i = 0
        
        while i < len(top_spenders_list) and i < n:
            id, amount = top_spenders_list[i]
            strs = id + "(" + str(amount) + ")"
            top.append(strs)
            i += 1
        
        return top
            
    def schedule_payment(self, timestamp: int, account_id: str, amount: int, delay: int) -> str | None:
        if account_id not in self.accounts:
            return None
        payment_id = "payment" + str(self._next_payment_id)
        self._next_payment_id += 1

        p = Payment(account_id, amount, timestamp + delay, payment_id)
        heapq.heappush(self.sch_payments_timestamps, p)
        self.sch_payments[p.id] = p        
        return p.id
        
    def cancel_payment(self, timestamp: int, account_id: str, payment_id: str) -> bool:
        self._process_scheduled_payments(timestamp)
        if payment_id not in self.sch_payments:
            return False
        p = self.sch_payments[payment_id]
        if p.account_id != account_id:
            return False
        if timestamp > p.timestamp:
            return False
        self.sch_payments.pop(payment_id)
        self.sch_payments_timestamps.remove(p)
        return True

    def _process_scheduled_payments(self, timestamp: int) -> None:
        while self.sch_payments_timestamps and self.sch_payments_timestamps[0].timestamp <= timestamp:
            p = heapq.heappop(self.sch_payments_timestamps)
            # print(p.timestamp, p.id)
            if p.account_id in self.accounts:
                a = self.accounts[p.account_id]
                transaction_id = "withdraw" + str(self._next_transaction_id)
                self._next_transaction_id += 1
                a.withdraw(p.amount, timestamp, transaction_id)
            self.sch_payments.pop(p.id)
        