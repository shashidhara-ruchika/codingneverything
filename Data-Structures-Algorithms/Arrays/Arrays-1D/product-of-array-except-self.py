# https://leetcode.com/problems/product-of-array-except-self/description/

# https://neetcode.io/problems/products-of-array-discluding-self?list=neetcode150

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # nums [     1, 2, 3, 4]

        # lprefix [  1, 1, 2, 6]
        # res     [  1, 1, 2, 6]
        # rprefix [ 24,12, 4, 1]
        # res     [24, 12, 8, 6]

        res = [1 for i in range(len(nums))]

        lprefix = nums[0]
        for i in range(1, len(nums)):
            res[i] *= lprefix
            lprefix *= nums[i]

        rprefix = nums[len(nums) - 1]
        for i in range(len(nums) - 2, -1, -1):
            res[i] *= rprefix
            rprefix *= nums[i]

        return res

class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # nums [  1, 2, 3, 4]
        # ltor [  1, 1, 2, 6]
        # rtol [24, 12, 4, 1]
        # res [ 24, 12, 8, 6]

        ltor_muls = [1 for i in range(len(nums))]
        for i in range(1, len(nums)):
            ltor_muls[i] *= ltor_muls[i - 1] * nums[i - 1]
        
        
        rtol_muls = [1 for i in range(len(nums))]
        for i in range(len(nums) - 2, -1, -1):
            rtol_muls[i] *= rtol_muls[i + 1] * nums[i + 1]
        
        return [ltor_muls[i] * rtol_muls[i] for i in range(len(nums))]

class Solution3:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        # nums [  1, 2, 3, 4]
        # ltor [  1, 2, 6, 24]
        # rtol [24, 12, 4, 1]
        # res [ 24, 12, 8, 6]
    
        # ltor_muls = [i for i in nums]
        # for i in range(1, len(nums)):
        #     ltor_muls[i] *= ltor_muls[i - 1]

        ltor_muls = [1 * nums[i] if i == 0 else nums[i - 1] * nums[i] for i in range(len(nums))]
        
        rtol_muls = [i for i in nums]
        for i in range(len(nums) - 2, -1, -1):
            rtol_muls[i] *= rtol_muls[i + 1]
        
        res = [rtol_muls[0 + 1]]
        for i in range(1, len(nums) - 1):
            res.append(ltor_muls[i - 1] * rtol_muls[i + 1])
        res.append(ltor_muls[len(nums) - 2])

        return res



