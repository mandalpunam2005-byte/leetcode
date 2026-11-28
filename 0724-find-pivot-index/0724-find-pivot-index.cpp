class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long leftSum = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            long long rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};