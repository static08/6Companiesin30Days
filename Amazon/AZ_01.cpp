// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int N, int A[]) {    
       int dp[k+1][N];
       memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=k;i++)
        {
            int m = INT_MIN;
            
            for(int j=1; j<N; j++)
            {
                m = max(m,dp[i-1][j-1] - A[j-1]);
                dp[i][j] = max(dp[i][j-1],m+A[j]);
            }
        }
        
        return dp[k][N-1];
    }
        
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
