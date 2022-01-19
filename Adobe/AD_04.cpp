# Partition Equal Subset Sum 

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i=0; i<N; i++)
            s+= arr[i];
            
        if(s%2 != 0)
            return 0;
        
        vector<vector<bool>> dp(N+1, vector<bool>(s+1,false));
        for(int i=0; i<=N; i++)
            dp[i][0] = true;
            
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<= s; j++)
            {
                if(arr[i-1] <=j)
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[N][s/2] == true)
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
