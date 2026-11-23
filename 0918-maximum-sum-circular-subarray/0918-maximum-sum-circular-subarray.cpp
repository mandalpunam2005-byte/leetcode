class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = nums[0];
        
        int currMax = nums[0];
        int maxSum = nums[0];
        
        int currMin = nums[0];
        int minSum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            totalSum += x;
            
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);
            
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }
        
        // If all elements are negative, maxSum holds the maximum single element
        if (maxSum < 0) {
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};