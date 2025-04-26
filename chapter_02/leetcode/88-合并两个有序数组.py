# @leet start
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        temp = nums1[:m]
        i, j, k = 0, 0, 0
        while (i != m and j != n):
            if (temp[i] <= nums2[j]):
                nums1[k] = temp[i]
                i += 1
            else:
                nums1[k] = nums2[j]
                j += 1
            k += 1
        while (i != m):
            nums1[k] = temp[i]
            i += 1
            k += 1
        while (j != n):
            nums1[k] = nums2[j]
            j += 1
            k += 1
        """
        Do not return anything, modify nums1 in-place instead.
        """
# @leet end

