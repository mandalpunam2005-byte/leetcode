class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for (int num : nums) {
            // Kadane's for Maximum Subarray Sum
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Kadane's for Minimum Subarray Sum
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);

            totalSum += num;
        }

        // If all numbers are negative, maxSum will be negative and equal to max element.
        // In this case, wrapping around is not allowed (would result in 0).
        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};