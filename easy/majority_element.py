#Majority Element

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=0
        c=None
        for i in nums:
            if count==0:
                c=i
                count+=1
            elif c==i:
                count+=1
            else:
                count-=1
        return c
