#Brackets in Matrix Chain Multiplication

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long dp[501][501];
    int bp[501][501];
    void printString(int i,int j,string &ans)
    {   
        if(i>j)
        return;
        if(i==j-1 or i==j)
        {
            ans+='A'+j-1;
            return;
        }
        ans+='(';
        printString(i,bp[i][j],ans);
        printString(bp[i][j],j,ans);
        ans+=')';
    }
    
    long long recurse(int i,int j,int arr[])
    {
        if(i==j-1 or i==j)
        {
            bp[i][j]=j;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long mn=1e18;
        int brkpt=0;
        for(int k=i+1;k<j;k++)
        {
            long long val=recurse(i,k,arr)+recurse(k,j,arr)+arr[i]*arr[k]*arr[j];
            if(val<=mn)
            {
                mn=val;
                brkpt=k;
            }
        }   
        bp[i][j]=brkpt;
        return dp[i][j]=mn;
    }

    string matrixChainOrder(int p[], int n)
    {
        memset(dp,-1,sizeof dp);
        long long x=recurse(0,n-1,p);
        string ans="";
        printString(0,n-1,ans);
        return ans;
    }
    };

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
