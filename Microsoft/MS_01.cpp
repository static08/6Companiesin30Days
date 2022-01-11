# Minimum sum partition 

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s1 = 0;
	    
	    for(int i=0;i<n; i++)
	        s1+=arr[i];
	    
	    vector<bool> dp(s1/2 +1,false);
	    
	    dp[0] = true;
	    
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=s1/2;j>=arr[i-1];j--)
	        {
	            if(j==0) dp[j]= false;
	            else dp[j] = dp[j] || dp[j-arr[i-1]];
	        }
	    }
	    
	    int diff;
	    
	    for(int i=0; i<=s1/2; i++)
	    {
	        if(dp[i])
	            diff = s1-2*i;
	    }
	    
	    return diff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
