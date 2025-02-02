#Plus One

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        for i in range(n - 1, -1, -1):  # Iterate from right to left
            digits[i] += 1
            if digits[i] < 10:  # No carry-over
                return digits
            digits[i] %= 10  # Handle carry-over

        # If we reach here, it means there was a carry-over to the most significant digit
        digits.insert(0, 1)  # Add the carry-over at the beginning
        return digits
