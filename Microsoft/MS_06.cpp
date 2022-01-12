# Possible Words From Phone Digits

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    string stl(int n)
    {
        switch(n) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }
    void word(int i, int n, int a[], string t, vector<string>&ans)
    {
        if(i==n)
        {
            ans.push_back(t);
            return;
        }
        
        string s = stl(a[i]);
        
        for(int j=0; j<s.size(); j++)
            word(i+1,n,a,t+s[j],ans);
            
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        word(0,N,a,"",ans);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
