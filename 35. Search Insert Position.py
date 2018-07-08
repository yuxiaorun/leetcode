class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        p = 0
        if target > nums[-1]:
            return len(nums)
        for i in range(len(nums)):
            if target <= nums[i]:
                p = i
                break
        return i
