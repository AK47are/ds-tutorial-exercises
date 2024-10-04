# @leet start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        res = len(nums) - nums.count(val)
        while nums.count(val) != 0:
            nums.remove(val)
        return res
# @leet end
