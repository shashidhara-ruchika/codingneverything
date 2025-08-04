from abc import ABC


class BankingSystem(ABC):
    """
    `BankingSystem` interface.
    """

    def create_account(self, timestamp: int, account_id: str) -> bool:
        """
        Should create a new account with the given identifier if it
        does not already exist.
        Returns `True` if the account was successfully created or
        `False` if an account with `account_id` already exists.
        """
        # default implementation
        return False

    def deposit(self, timestamp: int, account_id: str, amount: int) -> int | None:
        """
        Should deposit the given `amount` of money to the specified
        `account_id`.
        Returns the total amount of money in the account after the
        query has been processed.
        If the specified account does not exist, should return
        `None`.
        """
        # default implementation
        return None

    def transfer(self, timestamp: int, source_account_id: str, target_account_id: str, amount: int) -> int | None:
        """
        Should transfer the given amount of money from account
        `source_account_id` to account `target_account_id`.
        Returns the balance of `source_account_id` if the transfer
        was successful or `None` otherwise.
          * Returns `None` if `source_account_id` or
          `target_account_id` doesn't exist.
          * Returns `None` if `source_account_id` and
          `target_account_id` are the same.
          * Returns `None` if account `source_account_id` has
          insufficient funds to perform the transfer.
        """
        # default implementation
        return None

    def top_spenders(self, timestamp: int, n: int) -> list[str]:
        """
        Should return identifiers of the top `n` accounts with the
        highest amount of outgoing transactions - the total amount
        of money either transferred out of or paid/withdrawn (via
        the **schedule_payment** operation which will be introduced
        in level 3) - sorted in descending order, or in case of a
        tie, sorted alphabetically by `account_id` in ascending
        order.
        The output should be a list of strings in the following
        format: `["<account_id_1>(<total_outgoing_1>)", "<account_id
        _2>(<total_outgoing_2>)", ..., "<account_id_n>(<total_outgoi
        ng_n>)"]`.
          * If less than `n` accounts exist in the system, then return
          all their identifiers (in the described format).
        """
        # default implementation
        return []

    def schedule_payment(self, timestamp: int, account_id: str, amount: int, delay: int) -> str | None:
        """
        Should schedule a payment which will be performed at
        `timestamp + delay`.
        Returns a string with a unique identifier for the scheduled
        payment in the following format: `"payment[ordinal number of
         the scheduled payment across all accounts]"` - e.g.,
        `"payment1"`, `"payment2"`, etc.
        If `account_id` doesn't exist, should return `None`.
        The payment is skipped if the specified account has
        insufficient funds when the payment is performed.
        Additional conditions:
          * Successful payments should be considered outgoing
          transactions and included when ranking accounts using the
          `top_spenders` operation.
          * Scheduled payments should be processed **before** any
          other transactions at the given timestamp.
          * If an account needs to perform several scheduled payments
          simultaneously, they should be processed in order of
          creation - e.g., `"payment1"` should be processed before
          `"payment2"`.
        """
        # default implementation
        return None

    def cancel_payment(self, timestamp: int, account_id: str, payment_id: str) -> bool:
        """
        Should cancel the scheduled payment with `payment_id`.
        Returns `True` if the scheduled payment is successfully
        canceled.
        If `payment_id` does not exist or was already canceled, or
        if `account_id` is different from the source account for the
        scheduled payment, returns `False`.
        Note that scheduled payments must be performed before any
        `cancel_payment` operations at the given timestamp.
        """
        # default implementation
        return False
