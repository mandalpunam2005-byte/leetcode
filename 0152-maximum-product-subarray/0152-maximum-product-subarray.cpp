class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;
        
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            
            // Temporary variable to hold the max before min_so_far gets updated
            int temp_max = max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = min({curr, max_so_far * curr, min_so_far * curr});
            
            max_so_far = temp_max;
            result = max(result, max_so_far);
        }
        
        return result;
    }
};