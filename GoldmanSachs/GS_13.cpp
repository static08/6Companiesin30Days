#Decode the string
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string ans = "";
    string str = "";
        string make(string s,int n)
        {
            string st = "";
            while(n--)
            {
                st = st+s;
            }
            return st;
        }
        string decodedString(string s){
           
            int n = s.length();
            int k,start;
            int flag=1;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    k = stol(s.substr(0,i+1));
                }
                else
                {
                    break;
                }
            }
            
            int last = 1;
            
            for(int i=1;i<n;i++)
            {
                
                if(s[i]>='a' && s[i]<='z')
                {
                    str = str+s[i];
                    flag=1;
                }
                else if(s[i]==']')
                {
                    ans = ans+ make(str,last);
                    last=1;
                    flag=1;
                    str.clear();
                    
                }
                else if(s[i]=='[')
                {
                    if(s[i-1]>='a' && s[i-1]<='z'){
                    ans = ans + str;
                    }
                    flag=1;
                    str.clear();
                }
                else
                {
                    if(flag==1)
                    {
                         start = i;
                        flag=0;
                    }
                    
                    last = stol(s.substr(start,i+1)) ;
                    
                    if(s[i-1]>='a' && s[i-1]<='z')
                    {
                    ans = ans + str;
                    }
                }
            }
            ans = make(ans,k);
            return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
