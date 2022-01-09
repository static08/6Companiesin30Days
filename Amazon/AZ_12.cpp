# Column name from a given column number

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string ans = "";
    string colName (long long int n)
    {
        if(n/26 == 0)
        {
            ans += (n-1+'A');
            return ans;
        }
        long long q = n/26;
        long long r = n%26;
        //ans += (q-1 +'A');
        //cout<<"\nQ: "<<q<<"  R: "<<r<<endl;
        if(r == 0)  ans = colName(q-1);
        else ans = colName(q);
        if(r == 0)
            ans+='Z';
        else ans += (r-1 + 'A');
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
