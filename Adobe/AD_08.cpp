# Implement Atoi
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

    int atoi(string s) {
        //Your code here
        int n = s.size();
        int num = 0;
        int pos = 1;
        for(int i=0; i<n; i++)
        {
            if(s[0] == '-')
                pos = -1;
            if(s[i]>= '0' && s[i]<='9')
            {
                int n1 = s[i] -'0';
                num = num*10 + n1;
            }
            else if(s[i]>='a' && s[i]<='z') return -1;
        }
        //cout<<pos<<endl;
        return num*pos;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
