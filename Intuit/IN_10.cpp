# Number of Provinces
class Solution {
public:
   void dfs(vector<vector<int>>& link, int i,int j)
   {
        link[i][j] = 0;
        for(int x=0;x<link.size();x++){
            if(link[j][x]==1){dfs(link,j,x);}
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int maxp=0;
        vector<int> vis(isConnected[0].size(),0);
        for(int i=0;i<isConnected.size();i++){
            for(auto j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    maxp++;
                    dfs(isConnected,i,j);
                }
            }
        }
        return maxp;
    }
};
