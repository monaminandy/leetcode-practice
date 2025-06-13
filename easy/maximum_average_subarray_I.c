#include <stdio.h> // For standard I/O (optional for LeetCode submission)
#include <limits.h> // For INT_MIN or similar if needed, not directly for this problem

double findMaxAverage(int* nums, int numsSize, int k) {
    long long current_sum = 0;
     for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    long long max_sum=current_sum;

    for (int i = k; i < numsSize; i++) { 
        current_sum = current_sum - nums[i - k] + nums[i]; 
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return (double)max_sum / k;
}
