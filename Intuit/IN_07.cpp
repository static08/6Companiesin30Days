# Capacity To Ship Packages Within D Days
class Solution {
public:
    bool ispos(vector<int>& weights, int mid, int days)
    {
        int c = 1;
        int w = 0;
        
        for(auto &it: weights)
        {
            w+= it;
            
            if(w>mid)
            {
                w = it;
                c++;
            }
        }
        
        return c <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = accumulate(weights.begin(),weights.end(),0);
        int lo = *max_element(weights.begin(),weights.end());
        int hi = sum;
        int ans ;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(ispos(weights,mid,days))
            {
                ans = mid;
                hi = mid-1;
            }
            else    lo = mid+1;
        }
        
        return ans;
    }
};
