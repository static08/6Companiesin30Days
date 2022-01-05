#Array Pair Sum Divisibility Problem

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> m;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            m[nums[i]%k]++;
            
        for(int i=0; i<n; i++)
        {
            int r = nums[i]%k;
            if(r==0)
            {
                if(m[0] & 1)
                    return false;
            }
            else if(m[r] != m[k-r])
                return false;
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
