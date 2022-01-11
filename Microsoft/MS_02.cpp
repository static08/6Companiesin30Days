# Prerequisite Tasks

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool helper(vector<int> adj[],vector<int> &vis,vector<int> &mp,int i){
        vis[i] = 1;
        mp[i] = 1;
        for(int j : adj[i]){
            if(vis[j] == 0){
                if(helper(adj,vis,mp,j)) return true;
            }
            else if(mp[j] == 1){
                return true;
            }
        }
        mp[i] = 0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    for(auto i : pre){
	        adj[i.first].push_back(i.second);
	    }
	    vector<int> vis(N,0);
	    vector<int> mp(N,0);
	    for(int i = 0 ; i < N ; i ++){
	        if(vis[i] == 0){
	            if(helper(adj,vis,mp,i))
	                return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
