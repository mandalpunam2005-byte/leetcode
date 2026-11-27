#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            prefixSum += (nums[i] == 1) ? 1 : -1;

            if (firstIndex.find(prefixSum) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefixSum]);
            } else {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};