# Largest number in K swaps

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void MaxUtil(string str, string &max, int k, int pos)
    {
        if(k == 0)
            return;
            
        char maxm = str[pos];
        for(int i = pos+1; i < str.length() ;i++)
        {
            if(maxm < str[i])
                maxm = str[i];
        }
        
        if(maxm != str[pos])
            k--;
            
        for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == maxm)
            {
                swap(str[i], str[pos]);
                if(str.compare(max) > 0)
                    max = str;
                    
                MaxUtil(str, max, k, pos+1);
                
                swap(str[i], str[pos]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {

       string max = str;
       MaxUtil(str, max, k, 0);
       return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends