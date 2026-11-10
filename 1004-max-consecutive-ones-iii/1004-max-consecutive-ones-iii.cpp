#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0;
        int maxLen = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            maxLen = std::max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};