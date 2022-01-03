#Program to find Nth Ugly Number

class Solution{
public:	
	ull getNthUglyNo(int n) {
	    vector<long> dp(n+1);
	    int p1 =0, p2=0, p3=0;
	    dp[0]=1;
	    
	    for(int i=1; i<=n; i++)
	    {
	        dp[i] = min(dp[p1]*2,min(dp[p2]*3,dp[p3]*5));
	        
	        if(dp[i] == dp[p1]*2)
	            p1++;
	        if(dp[i] == dp[p2]*3)
	            p2++;
	        if(dp[i] == dp[p3]*5)
	            p3++;
	    }
	    
	    return dp[n-1];
	}
};
