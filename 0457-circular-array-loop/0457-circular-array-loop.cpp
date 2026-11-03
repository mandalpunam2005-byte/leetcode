class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            
            // Fast and slow pointers
            int slow = i, fast = i;
            bool isForward = nums[i] > 0;
            
            while (true) {
                // Move slow pointer 1 step
                slow = getNextIndex(nums, slow, isForward);
                if (slow == -1) break;
                
                // Move fast pointer 2 steps
                fast = getNextIndex(nums, fast, isForward);
                if (fast == -1) break;
                fast = getNextIndex(nums, fast, isForward);
                if (fast == -1) break;
                
                if (slow == fast) {
                    return true; // Cycle found
                }
            }
            
            // Mark all elements along this path as 0 (visited / dead-end)
            int curr = i;
            bool expectedDirection = nums[i] > 0;
            while (nums[curr] != 0 && (nums[curr] > 0) == expectedDirection) {
                int next = getNextIndex(nums, curr, expectedDirection);
                nums[curr] = 0;
                curr = next;
                if (curr == -1) break;
            }
        }
        
        return false;
    }
    
private:
    int getNextIndex(const vector<int>& nums, int i, bool isForward) {
        bool direction = nums[i] > 0;
        if (direction != isForward) return -1; // Direction changed
        
        int n = nums.size();
        int next = (i + nums[i]) % n;
        if (next < 0) next += n;
        
        if (next == i) return -1; // Cycle of length 1
        
        return next;
    }
};