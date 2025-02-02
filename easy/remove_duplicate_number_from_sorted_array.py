#Remove Duplicate Number From Sorted Array
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        j=1
        for i in range (1, len(nums)):
            if (nums[i-1]!=nums[i]):
                nums[j] = nums[i]
                j=j+1
        return j
