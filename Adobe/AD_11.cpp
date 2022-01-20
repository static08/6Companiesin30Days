# Amend The Sentence
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            if(s[i]>='A' && s[i] <='Z')
            {
                if(i!=0)
                    ans += " ";
                ans+= tolower(s[i]);
            }
            else if(s[i]>='a' && s[i] <='z')
                ans+= s[i];
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
