#include<stdio.h>
#include<stdlib.h>

int max (int a, int b){
    if (a>b){
        return a;
    }
    else {
        return b;
    }
}

int maxAdjacentDistance(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int max_diff = abs(nums[0] - nums[1]);
    for (int i = 0; i < numsSize - 1; i++){
        int diff = abs(nums[i] - nums[i+1]);
        max_diff = max(max_diff, diff);
    }

    int circu_diff = abs(nums[numsSize - 1] - nums[0]);
    max_diff = max(max_diff, circu_diff);
    return max_diff;

}
