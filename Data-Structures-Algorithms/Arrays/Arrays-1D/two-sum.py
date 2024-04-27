# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numdict = {}
        for i in range(len(nums)):
            if nums[i] in numdict:
                numdict[nums[i]].append(i)
            else:
                numdict[nums[i]] = [i]
        l = []
        for i in range(len(nums)):
            diff = target - nums[i]
            l.append(diff)
            if diff in numdict:
                if diff != nums[i]:
                    return [i, numdict[diff][0]]
                else:
                    if len(numdict[diff]) > 1:
                        return [numdict[diff][0], numdict[diff][1]]

        return [0,0]


        