#Count the subarrays having product less than k

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int m = 1,c =0,i=0,j=0;

        while(i<n)
        {
            m*=a[i];
            while(j<n && m >=k)
            {
                m = m/a[j];
                j++;
            }
            
            if(m<k)
                c+= i - j +1;
                
            i++;
        }
        return c;
    }
};
