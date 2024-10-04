# @leet start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 2
        for x in nums[2:]:
            if (nums[k - 2] != x):
                nums[k] = x
                k += 1
        return k

# @leet end

