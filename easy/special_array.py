class Solution:
    def isArraySpecial(self, nums):
        for index in range(len(nums) - 1):
            if ((nums[index] & 1) ^ (nums[index + 1] & 1)) == 0:
                return False
        return True
