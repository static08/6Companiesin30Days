# Koko Eating Bananas
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int lo = 1;
        int hi = piles[n-1];
        int mid, ans;
        ans = INT_MAX;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            int t = 0;
            //cout<<"MID "<<mid<<endl;
            for(int i=0; i<n; i++)
            {
                int c = piles[i]/mid + (piles[i]%mid !=0);
                //cout<<" "<<c;
                t+=int(c);    
            }
            //cout<<" T: "<<t;
            //cout<<endl;
            if(t<=h && mid>0)
            {
                ans = min(ans,mid);
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        
        return ans;
    }
};
