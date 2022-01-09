# Nuts and Bolts Problem
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    unordered_map<char, int> mp;
	    string s = "!#$%&*@^~";
	    for(int i=0; i<9; i++)
	        mp.insert(make_pair(s[i],0));
	    
	    for(int i=0; i<n; i++)
	    {
	        mp[nuts[i]] ++;
	        mp[bolts[i]] ++;
	    }
	    vector<char> sol;
        for(int i=0; i<9; i++)
        {
            if(mp[s[i]] == 2)
                sol.push_back(s[i]);
        }
        for(int i=0; i<n; i++)
        {
            nuts[i] = sol[i];
            bolts[i] = sol[i];
        }
        
        return;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
