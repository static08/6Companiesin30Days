# Split Array Largest Sum
class Solution {
public:
    int dp[1001][5001];
    
    int getmin(vector<int>& psum, int cs, int c)
    {
        int n = psum.size()-1;
        
        if(dp[cs][c] != -1) return dp[cs][c];
        if(c == 1)  return dp[cs][c] = psum[n]-psum[cs];
        
        int minsum = INT_MAX;
        
        for(int i = cs; i<=n-c; i++)
        {
            int fss = psum[i+1] - psum[cs];
            int lss = max(fss,getmin(psum,i+1,c-1));
            
            minsum = min(minsum,lss);
            if(fss >= minsum)   break;
        }
        
        return dp[cs][c] = minsum;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        
        int n = nums.size();
        vector<int> psum(n+1,0);
        for(int i=0; i<n; i++)
            psum[i+1] = psum[i] + nums[i];
        return getmin(psum,0,m);
    }
};
