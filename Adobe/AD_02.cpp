# Longest Arithmetic Progression

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        
        vector<unordered_map<int,int>> diff(n);
        int m = INT_MIN;
        if(n==1)
            return 1;
        if(n ==2)
            return 2;
        for(int i=1; i<n; i++)
        {
            for(int j= 0; j<i; j++)
            {
                int d = A[i]-A[j];
                if(diff[j].find(d) != diff[j].end()) diff[i][d] = diff[j][d]+1;
                else diff[i][d] = 2;
                
                m = max(m,diff[i][d]);
            }
        }
    
        return m;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
