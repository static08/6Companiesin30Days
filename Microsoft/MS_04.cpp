# Spirally traversing a matrix
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int rs = 0;
        int re = r -1;
        int cs = 0;
        int ce = c-1;
        int cn = 0;
        int t = r*c;
        
        while(cn<t)
        {
            for(int i= cs; cn<t && i<=ce ;i++)
            {
                ans.push_back(matrix[rs][i]);
                cn++;
            }
            rs++;
            
            for(int i = rs; cn<t && i<=re; i++)
            {
                ans.push_back(matrix[i][ce]);
                cn++;
            }
            ce--;
            
            for(int i= ce; cn<t && i>= cs; i--)
            {
                ans.push_back(matrix[re][i]);
                cn++;
            }
            re--;
            
            for(int i= re; cn<t && i>=rs; i--)
            {
                ans.push_back(matrix[i][cs]);
                cn++;
            }
            cs++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
