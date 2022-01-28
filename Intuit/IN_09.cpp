# Pacific Atlantic Water Flow
class Solution {
public:
    void solve(int i,int j,int m,int n,vector<vector<int>>& h, vector<vector<int>>& t,int prev)
    {
        if(i<0 || j<0 || i>=m || j>=n || t[i][j]!=-1 || h[i][j]<prev)
        {
            return;
        }
        t[i][j]=1;
        solve(i+1,j,m,n,h,t,h[i][j]);
         solve(i-1,j,m,n,h,t,h[i][j]);
         solve(i,j+1,m,n,h,t,h[i][j]);
         solve(i,j-1,m,n,h,t,h[i][j]);
        
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        int m=h.size();
        int n=h[0].size();
        vector<vector<int>> temp1(m,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            solve(0,i,m,n,h,temp1,-1);
        }
          for(int i=0;i<m;i++)
        {
            solve(i,0,m,n,h,temp1,-1);
        }
         vector<vector<int>> temp2(m,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            solve(m-1,i,m,n,h,temp2,-1);
        }
          for(int i=0;i<m;i++)
        {
            solve(i,n-1,m,n,h,temp2,-1);
        }
        vector<vector<int>> re;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp1[i][j]==1 && temp2[i][j]==1)
                {
                    re.push_back({i,j});
                }
            }
            
            
        }
        return re;
    }
};
