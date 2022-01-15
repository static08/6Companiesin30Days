# Minimum steps to destination

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSteps(int D){
        // code here
        int sum = 0;
        int steps = 0;
        while(sum < D)
        {
            sum += steps;
            steps++;
        }
        
        while((sum-D)%2)
        {
            sum-= steps;
            steps++;
        }
        
        return steps-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
