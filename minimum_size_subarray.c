#include <limits.h> 
#include <stdio.h>  

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    int minLength = INT_MAX;
    int currentSum = 0;
    int left = 0;
    int right = 0;

    for (right = 0; right < numsSize; right++) {
        currentSum += nums[right];

        
        while (currentSum >= target) {
            minLength = min(minLength, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}

