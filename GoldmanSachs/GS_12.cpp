#Squares in N*N Chessboard 

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
  // METHOD 1 : Iterative methode
  // Time complexity : O(N)
    long long squaresInChessBoard(long long N) {
        long long ans =0;
        
        while(N >=1)
        {
            ans += (N*N);
            N--;
        }
        
        return ans;
    }
  
  //METHOD 2 : Formula based
  // Time Complexity : O(1)

  long long squaresInChessBoard(long long N) {
          if(N==1) 
            return 1;
          return (N*N)+squaresInChessBoard(N-1);
      }

};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
