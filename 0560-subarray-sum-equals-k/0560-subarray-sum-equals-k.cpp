#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int currSum = 0;
        int count = 0;

        for (int num : nums) {
            currSum += num;

            auto it = prefixCount.find(currSum - k);
            if (it != prefixCount.end()) {
                count += it->second;
            }

            prefixCount[currSum]++;
        }

        return count;
    }
};