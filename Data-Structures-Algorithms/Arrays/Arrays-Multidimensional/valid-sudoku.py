# https://leetcode.com/problems/valid-sudoku/

# https://neetcode.io/problems/valid-sudoku?list=neetcode150

class Solution:
    def isValidRow(self, board: List[List[str]], row_num: int) -> bool:
        nums = set()
        for i in range(9):
            num = board[row_num][i]
            if num != ".":
                if num <= "0" or num > "9" or num in nums:
                    return False
                else:
                    nums.add(num)
        return True

    def isValidCol(self, board: List[List[str]], col_num: int) -> bool:
        nums = set()
        for i in range(9):
            num = board[i][col_num]
            if num != ".":
                if num <= "0" or num > "9" or num in nums:
                    return False
                else:
                    nums.add(num)
        return True

    def isValidGrid(self, board: List[List[str]], start_row_num: int, start_col_num: int) -> bool:
        nums = set()
        for i in range(3):
            for j in range(3):
                num = board[i + start_row_num][j + start_col_num]
                if num != ".":
                    if num <= "0" or num > "9" or num in nums:
                        return False
                    else:
                        nums.add(num)
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if not self.isValidRow(board, i):
                return False
            if not self.isValidCol(board, i):
                return False
            
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                if not self.isValidGrid(board, i, j):
                    return False

        return True
            

        