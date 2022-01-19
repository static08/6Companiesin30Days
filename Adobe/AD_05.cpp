# Express as sum of power of natural numbers 
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<long long>> dp;
    long long dpp(int n, int x, int curr) {
        if(n == 0) return 1;
        else if(curr == 0) return 0;
        long long &ans = dp[n][curr];
        if(ans != -1) return ans;
        long long p = pow(curr, x);
        return ans = (n - p >= 0 ? dpp(n - p, x, curr - 1): 0) + dpp(n, x, curr - 1);
    }
    long long numOfWays(long long n, int x) {
        int num = pow(n, 1.0 / x);
        dp.resize(n + 1, vector<long long>(num + 1, -1));
        return dpp(n, x, num);
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
