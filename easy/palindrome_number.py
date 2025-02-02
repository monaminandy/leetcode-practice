#Palindrome Number

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        x_str=str(x)
        y=x_str[::-1]
        return x_str == y
