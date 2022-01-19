# Generate Parentheses
#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;

class Solution
{
    public:
    vector<string> ans;
    void help(int i, int j, string s)
    {
        if(i==0 && j == 0)
        {
            ans.push_back(s);
            return;
        }
        if(i>=0) help(i-1,j,s+"(");
        if(j>i) help(i,j-1,s+")");
    }
    vector<string> AllParenthesis(int n) 
    {
        help(n,n,"");
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
