# Unit Area of largest region of 1's
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int mc = INT_MIN;
    void dfs(vector<vector<int>>& grid,int i,int j, int r,int c,int& tc)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 )
            return ;
        tc++;
        grid[i][j] = 0;
        dfs(grid,i-1,j,r,c,tc);
        dfs(grid,i+1,j,r,c,tc) ;
        dfs(grid,i,j-1,r,c,tc) ;
        dfs(grid,i,j+1,r,c,tc) ;
        dfs(grid,i-1,j-1,r,c,tc) ;
        dfs(grid,i+1,j+1,r,c,tc);
        dfs(grid,i+1,j-1,r,c,tc) ;
        dfs(grid,i-1,j+1,r,c,tc);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
       int row = grid.size();
       int col = grid[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int tc = 0;
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,row,col,tc);
                    mc = max(mc,tc);
                }
            }
        }
        
        return mc;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
