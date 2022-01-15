# Count Number of SubTrees having given Sum
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to count number of subtrees having sum equal to given sum.
int sc = 0;
int dfs(Node* root, int X)
{
    if(!root)
        return 0;
    
    int l = dfs(root->left,X);
    int r = dfs(root->right,X);
    int s = l+r+root->data;
    if(s == X)
        sc++;
    
    return s;
}
int countSubtreesWithSumX(Node* root, int X)
{
    sc = 0;
	int ans = dfs(root,X);
	return sc;
}

int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
     string s;
     getline(cin,s);
     Node* root = buildTree(s);
     
     int x;
     cin>>x;
     getchar();
     cout << countSubtreesWithSumX(root, x)<<endl;
  }
  return 0;
}
