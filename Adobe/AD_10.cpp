# Winner of an election 

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

class Solution{
  public:
    vector<string> winner(string arr[],int n)
    {
        sort(arr,arr + n);
        map<string,int> mp;
        
        for(int i=0; i<n; i++)
        {
            if(mp.find(arr[i]) != mp.end()) mp[arr[i]]++;
            else    mp[arr[i]] = 1;
        }
        
        int m = INT_MIN;
        string name = "";
        for(auto it: mp)
            m = max(m,it.second);
        
        for(auto it: mp)
        {
            if(m == it.second)
            {
                name = it.first;
                break;
            }
        }
        
        return {name,to_string(m)};
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
