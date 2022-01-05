#Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_size = INT_MAX;
        int cur_sum = 0;
        int e=0;
        
        for(int i=0; i<n; i++)
        {
            cur_sum += nums[i];
            
            while(cur_sum >= target)
            {
                min_size = min(min_size,i-e+1);
                cur_sum -= nums[e++];
            }
            
        }
        
        return (min_size!= INT_MAX)? min_size:0;
    }
};
