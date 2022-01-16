# Number of distict Words with k maximum contiguous vowels 
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

static const int MOD=1000000007;
static const int CHARS=26;
#define ms(a,b) (((a%MOD)+(b%MOD))%MOD)
class Solution
{
    public:
    vector<char> alphabet;
    vector<vector<int>> dp{};
    bool iw(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    int dfs(int N,int K,int C,int P){
        if(N==0)return 1;
        if(dp[N][C]!=-1)return dp[N][C];
        int ans{0};
        if(C==K){
            for(int j=0;j<CHARS;++j){
                if(iw(j+'a'))continue;
                ans=ms(ans,dfs(N-1,K,0,j+1));
            }
        }
        else{
            for(int j=0;j<CHARS;++j){
                if(iw(j+'a'))ans=ms(ans,dfs(N-1,K,C+1,j+1));
                else ans=ms(ans,dfs(N-1,K,0,j+1));
            }
        }
        return dp[N][C]=ans;
    }

    int kvowelwords(int N, int K) {
        alphabet.assign(CHARS,'a');
        iota(begin(alphabet),end(alphabet),'a');
        dp.assign(N+1,vector<int>(K+1,-1));
        return dfs(N,K,0,0);
    }
};



// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
