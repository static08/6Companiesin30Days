# Smallest range in K lists

#include<bits/stdc++.h>
using namespace std;
#define N 1000

struct compare{
    bool operator()(int *p1 , int *p2)
    {
        return p2[0]<=p1[0];
    }
};
class Solution{
    public:
  
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        priority_queue<int*,vector<int*>,compare> pq;
        int i,j;
        int mx = INT_MIN;
        int min_range = INT_MAX;
        for(i=0;i<k;i++)
        {
            int* n = new int[3];
            n[0] = a[i][0];
            n[1] = i;
            n[2] = 0;
            pq.push(n);
            mx = max(mx,a[i][0]);
        }
       bool flag = true;
       pair<int,int> ans;
        while(flag)
        {
            int* tp = pq.top();
            int p_min_range = min_range;
            min_range = min(min_range,mx-tp[0]);
            if(p_min_range != min_range) {ans.first = tp[0]; ans.second = mx;}
            pq.pop();
            if(tp[2] >= n-1)
            {
                flag=false;
            }
            else
            {
                int *n = new int[3];
                n[0] = a[tp[1]][tp[2]+1];
                n[1] = tp[1];
                n[2] = tp[2]+1;
                pq.push(n);
                mx = max(mx,a[tp[1]][tp[2]+1]);
            }
        }
        return ans;
    }
};
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
