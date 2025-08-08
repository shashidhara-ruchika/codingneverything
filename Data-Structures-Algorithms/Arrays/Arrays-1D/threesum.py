# https://leetcode.com/problems/3sum/description/

# https://neetcode.io/problems/three-integer-sum?list=neetcode150

class Solution:
    
    def threeSum(self, numbers: List[int]) -> List[List[int]]:
        
        res = []
        nums = sorted(numbers)
        
        for i, a in enumerate(nums):

            # If this isn't the first number in the array 
            # and it's the same as the number I just checked, 
            # I have already found all possible triplets for this value. 
            # Skip it and move on to the next unique number.
            if i > 0 and a == nums[i - 1]:
                continue
            
            l = i + 1
            r = len(nums) - 1

            while l < r:

                threesum = a + nums[l] + nums[r]

                if threesum > 0:
                    r -= 1
                elif threesum < 0:
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])
                    l += 1

                    # this line efficiently 
                    # skips over any consecutive duplicate values 
                    # for the second number in the triplet, 
                    # which is crucial for finding only unique solutions.
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        
        return res

            

        