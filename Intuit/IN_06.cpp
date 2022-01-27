# Find in Mountain Array
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mA) {
        int n = mA.length();
        int lo = 0;
        int hi = n-1;
        int mid = (hi+lo)/2;
        int p ;
        
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            
            if(mA.get(mid-1) < mA.get(mid) && mA.get(mid+1) < mA.get(mid))
            {
                p = mid;
                break;
            }
            else if( mA.get(mid+1) < mA.get(mid)) hi = mid;
            else lo = mid +1;
        }
        
        lo = 0,hi = p;
        
        if(target >= mA.get(lo) && target<= mA.get(hi))
        {
           while(lo<=hi)
            {
                mid = (lo+hi)/2;

                if(mA.get(mid) == target) return mid;
                else if(target < mA.get(mid))   hi = mid-1; 
                else lo = mid+1;
            }
        }
        lo = p+1;
        hi = n-1;
        
        if(target <= mA.get(lo) && target >= mA.get(hi))
        {
            while(lo<=hi)
            {
                mid = (lo+hi)/2;

                if(mA.get(mid) == target) return mid;
                else if(target > mA.get(mid))  hi = mid-1;
                else lo = mid+1;
            }   
        }        
        return -1;
    }
};
