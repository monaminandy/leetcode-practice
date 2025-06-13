#include <string.h>
#include <stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);

    if (n == 0) {
        return 0;
    }

    bool seen[128]; 
    for (int i = 0; i < 128; i++) {
        seen[i] = false;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        while (seen[(int)s[right]]) {
            seen[(int)s[left]] = false;
            left++;
        }
        
        seen[(int)s[right]] = true;
        
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
