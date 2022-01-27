# Number of Boomerangs
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        
        for(auto &it : points){
            map<double,int> mp;
            
            auto x1 = it[0];
            auto y1 = it[1];
             
            for(auto &i : points){
                
                if(i == it) continue;
                
                auto x2 = i[0];
                auto y2 = i[1];
                
                int x = (x1 - x2) * (x1 - x2);
                int y = (y1 - y2) * (y1 - y2);
                
                double D = sqrt(x + y);
                
                mp[D]++;
            }
            
            for(auto &iti : mp) 
				if(iti.second > 1)   ans += (iti.second * (iti.second-1)); 
	
        }
        
        return ans;
    }
};
