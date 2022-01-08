#Is Sudoku Valid

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        bool row[10][10] = {false}, col[10][10] = {false}, grid[10][10] = {false};
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
                int n = mat[i][j];
                if(n == 0) continue;
                int gi= (i/3) * 3 + (j/3);
                
                if(row[i][n] || col[j][n] || grid[gi][n])
                    return 0;
                
                row[i][n] = col[j][n] = grid[gi][n] = true;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
