# Longest Mountain

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int len =0, s = 0;
        while(s<n)
        {
            int e = s;
            
            if(e+1<n && arr[e] <arr[e+1])
            {
                while(e+1<n && arr[e]< arr[e+1])
                    e++;
                
             if(e+1<n && arr[e]>arr[e+1])
                {
                     while(e+1<n && arr[e] > arr[e+1])
                        e++;

                    len = max(len,e-s+1);
                }
               
            }
            
            s = max(e,s+1);
        }
        
        return len;
    }
};
