#First non-repeating character in a stream 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<int>q;
		    vector<int> freq(26,0);
		    int n = A.size();
		    for(int i=0; i<n; i++)
		    {
		        freq[A[i]-'a'] ++;
		        if(freq[A[i] - 'a'] == 1)
		            q.push(A[i]);
		      
		        while(!q.empty() && freq[q.front() - 'a'] != 1)
		            q.pop();
		      
		        if(q.empty()) A[i]= '#';
		        else A[i] = q.front();
		    }
		    
		    return A;
		}
		

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
