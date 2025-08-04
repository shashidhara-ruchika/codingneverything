
import inspect, os, sys
current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from timeout_decorator import timeout
import unittest
from banking_system_impl import BankingSystemImpl
""""""

class Level1Tests(unittest.TestCase):
    """
    The test suit below includes 10 tests for Level 1.

    All have the same score.
    You are not allowed to modify this file,
    but feel free to read the source code
    to better understand what is happening in every specific case.
    """

    failureException = Exception


    @classmethod
    def setUp(cls):
        cls.system = BankingSystemImpl()

    # @timeout(0.4)
    def test_level_1_case_01_basic_create(self):
        print("Running test_level_1_case_01_basic_create")
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))

    # @timeout(0.4)
    def test_level_1_case_02_basic_create_and_deposit(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))
        self.assertEqual(self.system.deposit(3, 'account1', 2500), 2500)
        self.assertEqual(self.system.deposit(4, 'account1', 500), 3000)
        self.assertEqual(self.system.deposit(5, 'account2', 1000), 1000)

    # @timeout(0.4)
    def test_level_1_case_03_basic_create_deposit_and_transfer_1(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))
        self.assertEqual(self.system.deposit(3, 'account1', 2000), 2000)
        self.assertEqual(self.system.deposit(4, 'account2', 1000), 1000)
        self.assertEqual(self.system.transfer(5, 'account1', 'account2', 500), 1500)
        self.assertEqual(self.system.deposit(6, 'account1', 100), 1600)
        self.assertEqual(self.system.deposit(7, 'account2', 100), 1600)

    # @timeout(0.4)
    def test_level_1_case_04_basic_create_deposit_and_transfer_2(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))
        self.assertTrue(self.system.create_account(3, 'account3'))
        self.assertEqual(self.system.deposit(4, 'account1', 2000), 2000)
        self.assertEqual(self.system.deposit(5, 'account2', 1000), 1000)
        self.assertEqual(self.system.transfer(6, 'account1', 'account2', 500), 1500)
        self.assertEqual(self.system.transfer(7, 'account2', 'account3', 1400), 100)
        self.assertEqual(self.system.deposit(8, 'account1', 100), 1600)
        self.assertEqual(self.system.deposit(9, 'account2', 100), 200)
        self.assertEqual(self.system.deposit(10, 'account3', 100), 1500)

    # @timeout(0.4)
    def test_level_1_case_05_create_edge_case(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertFalse(self.system.create_account(2, 'account1'))
        self.assertTrue(self.system.create_account(3, 'account2'))

    # @timeout(0.4)
    def test_level_1_case_06_deposit_edge_cases(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))
        self.assertEqual(self.system.deposit(3, 'account1', 100), 100)
        self.assertEqual(self.system.deposit(4, 'account2', 100), 100)
        self.assertIsNone(self.system.deposit(5, 'account3', 100))

    # @timeout(0.4)
    def test_level_1_case_07_transfer_edge_cases(self):
        self.assertTrue(self.system.create_account(1, 'account1'))
        self.assertTrue(self.system.create_account(2, 'account2'))
        self.assertEqual(self.system.deposit(3, 'account1', 2500), 2500)
        self.assertEqual(self.system.deposit(4, 'account1', 500), 3000)
        self.assertEqual(self.system.deposit(5, 'account2', 500), 500)
        self.assertEqual(self.system.deposit(6, 'account2', 500), 1000)
        self.assertIsNone(self.system.transfer(7, 'account3', 'account2', 500))
        self.assertIsNone(self.system.transfer(8, 'account1', 'account3', 500))
        self.assertIsNone(self.system.transfer(9, 'account1', 'account2', 3001))
        self.assertIsNone(self.system.transfer(10, 'account1', 'account1', 500))
        self.assertEqual(self.system.transfer(11, 'account1', 'account2', 3000), 0)
        self.assertTrue(self.system.create_account(12, 'account3'))
        self.assertIsNone(self.system.transfer(13, 'account3', 'account2', 100))

    # @timeout(0.4)
    def test_level_1_case_08_all_successful_operations(self):
        self.assertTrue(self.system.create_account(1, 'acc1'))
        self.assertTrue(self.system.create_account(2, 'acc2'))
        self.assertTrue(self.system.create_account(3, 'acc3'))
        self.assertEqual(self.system.deposit(4, 'acc3', 1000), 1000)
        self.assertEqual(self.system.deposit(5, 'acc2', 1000), 1000)
        self.assertEqual(self.system.transfer(6, 'acc3', 'acc2', 200), 800)
        self.assertEqual(self.system.transfer(7, 'acc2', 'acc3', 100), 1100)
        self.assertEqual(self.system.transfer(8, 'acc3', 'acc2', 100), 800)
        self.assertEqual(self.system.transfer(9, 'acc3', 'acc1', 150), 650)
        self.assertEqual(self.system.deposit(10, 'acc1', 100), 250)
        self.assertEqual(self.system.deposit(11, 'acc2', 100), 1300)
        self.assertEqual(self.system.deposit(12, 'acc3', 100), 750)

    # @timeout(0.4)
    def test_level_1_case_09_all_operations_1(self):
        self.assertTrue(self.system.create_account(1, 'acc1'))
        self.assertTrue(self.system.create_account(2, 'acc2'))
        self.assertTrue(self.system.create_account(3, 'acc3'))
        self.assertTrue(self.system.create_account(4, 'acc4'))
        self.assertEqual(self.system.deposit(5, 'acc1', 2000), 2000)
        self.assertEqual(self.system.deposit(6, 'acc4', 2000), 2000)
        self.assertEqual(self.system.deposit(7, 'acc3', 2000), 2000)
        self.assertEqual(self.system.deposit(8, 'acc2', 2000), 2000)
        self.assertIsNone(self.system.deposit(9, 'acc5', 2000))
        self.assertIsNone(self.system.deposit(10, 'acc6', 2000))
        self.assertIsNone(self.system.deposit(11, 'acc7', 2000))
        self.assertFalse(self.system.create_account(12, 'acc4'))
        self.assertFalse(self.system.create_account(13, 'acc1'))
        self.assertTrue(self.system.create_account(14, 'acc5'))
        self.assertEqual(self.system.deposit(16, 'acc5', 1000), 1000)
        self.assertEqual(self.system.transfer(17, 'acc5', 'acc1', 99), 901)
        self.assertEqual(self.system.transfer(18, 'acc5', 'acc2', 2), 899)
        self.assertEqual(self.system.transfer(19, 'acc5', 'acc3', 66), 833)
        self.assertIsNone(self.system.transfer(20, 'acc5', 'acc5', 2))
        self.assertEqual(self.system.transfer(21, 'acc5', 'acc3', 66), 767)
        self.assertEqual(self.system.transfer(22, 'acc5', 'acc2', 99), 668)
        self.assertEqual(self.system.deposit(23, 'acc1', 100), 2199)
        self.assertEqual(self.system.deposit(37, 'acc2', 200), 2301)
        self.assertEqual(self.system.deposit(38, 'acc3', 300), 2432)
        self.assertIsNone(self.system.transfer(39, 'acc5', 'acc5', 991))
        self.assertIsNone(self.system.transfer(43, 'acc6', 'acc3', 1))

    # @timeout(0.4)
    def test_level_1_case_10_all_operations_2(self):
        self.assertTrue(self.system.create_account(1, 'acc1'))
        self.assertTrue(self.system.create_account(2, 'acc2'))
        self.assertTrue(self.system.create_account(3, 'acc3'))
        self.assertTrue(self.system.create_account(4, 'acc4'))
        self.assertTrue(self.system.create_account(5, 'acc5'))
        self.assertEqual(self.system.deposit(6, 'acc1', 1000), 1000)
        self.assertEqual(self.system.deposit(7, 'acc4', 2000), 2000)
        self.assertEqual(self.system.deposit(8, 'acc3', 3000), 3000)
        self.assertEqual(self.system.deposit(9, 'acc2', 2000), 2000)
        self.assertEqual(self.system.deposit(10, 'acc5', 1000), 1000)
        self.assertIsNone(self.system.deposit(11, 'acc6', 100))
        self.assertIsNone(self.system.deposit(12, 'acc7', 1000))
        self.assertFalse(self.system.create_account(13, 'acc5'))
        self.assertFalse(self.system.create_account(14, 'acc3'))
        self.assertTrue(self.system.create_account(16, 'acc6'))
        self.assertEqual(self.system.deposit(17, 'acc6', 1000), 1000)
        self.assertEqual(self.system.transfer(18, 'acc6', 'acc1', 99), 901)
        self.assertEqual(self.system.transfer(19, 'acc6', 'acc2', 2), 899)
        self.assertEqual(self.system.transfer(20, 'acc6', 'acc3', 66), 833)
        self.assertEqual(self.system.transfer(21, 'acc6', 'acc5', 2), 831)
        self.assertEqual(self.system.transfer(22, 'acc6', 'acc3', 66), 765)
        self.assertEqual(self.system.transfer(23, 'acc6', 'acc2', 99), 666)
        self.assertEqual(self.system.transfer(24, 'acc6', 'acc1', 99), 567)
        self.assertEqual(self.system.transfer(25, 'acc6', 'acc5', 66), 501)
        self.assertEqual(self.system.transfer(26, 'acc6', 'acc5', 67), 434)
        self.assertEqual(self.system.transfer(27, 'acc6', 'acc5', 66), 368)
        self.assertEqual(self.system.transfer(28, 'acc6', 'acc5', 99), 269)
        self.assertEqual(self.system.transfer(29, 'acc6', 'acc3', 68), 201)
        self.assertEqual(self.system.transfer(30, 'acc6', 'acc4', 68), 133)
        self.assertEqual(self.system.transfer(31, 'acc6', 'acc4', 66), 67)
        self.assertEqual(self.system.transfer(32, 'acc6', 'acc5', 67), 0)
        self.assertIsNone(self.system.transfer(33, 'acc7', 'acc6', 100))
        self.assertIsNone(self.system.transfer(34, 'acc1', 'acc7', 100))
        self.assertIsNone(self.system.transfer(35, 'acc6', 'acc5', 1))
        self.assertIsNone(self.system.transfer(36, 'acc3', 'acc3', 239))
        self.assertEqual(self.system.deposit(37, 'acc1', 800), 1998)
        self.assertEqual(self.system.deposit(38, 'acc2', 800), 2901)
        self.assertEqual(self.system.deposit(39, 'acc3', 800), 4000)
        self.assertEqual(self.system.deposit(40, 'acc4', 800), 2934)
        self.assertEqual(self.system.deposit(41, 'acc5', 800), 2167)
        self.assertEqual(self.system.deposit(42, 'acc6', 1000), 1000)
        self.assertEqual(self.system.transfer(43, 'acc6', 'acc5', 991), 9)
        self.assertEqual(self.system.transfer(44, 'acc6', 'acc3', 1), 8)

if __name__ == '__main__':
    unittest.main()