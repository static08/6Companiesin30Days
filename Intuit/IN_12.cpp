# Course Schedule II
class Solution {
public:
    vector<int>ans;
    stack<int>s;
    bool dfs(int node,vector<int>&dvis,vector<int>&vis,vector<int>graph[])
    {
        vis[node]=1;
        dvis[node]=1;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                if(dfs(i,dvis,vis,graph)) return true;
            }
            else if(dvis[i]) return true;
        }
        s.push(node);
        dvis[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        for(auto i:prerequisites)graph[i[1]].push_back(i[0]);
        vector<int>vis(numCourses,0);
        vector<int>dvis(vis);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i] && dfs(i,dvis,vis,graph)) return {};   
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
