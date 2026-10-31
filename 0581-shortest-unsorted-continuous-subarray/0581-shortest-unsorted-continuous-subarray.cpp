class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n= nums.size() ;
      int start=-1, end= -2;
      int max_val=nums[0] ,min_val=nums[n-1];

      for(int i=1; i<n; i++){
        max_val=max(max_val, nums[i]);
        min_val=min(min_val, nums[n-1-i]);

        if(nums[i]<max_val) end=i;

        if(nums[n-1-i]> min_val)start=n-1-i;

      }
      return end-start+1;
    }
};