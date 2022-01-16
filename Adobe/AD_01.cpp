# Subarray with given sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        
        int lo = 0, hi = n-1, sum = 0, i= 0;
        while(lo<=hi)
        {
            sum+= arr[i];
            if(sum == s)
                return {lo+1,i+1};
            if(sum > s)
            {
                while(sum > s)
                {
                    sum-= arr[lo];
                    lo++;
                    if(sum == s)
                        return {lo+1,i+1};
                }
            }
            i++;
        }
        
        return {-1};
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
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
