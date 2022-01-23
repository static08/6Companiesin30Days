# Word Search

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int i, int j,int k)
    {
        int r = board.size();
        int c = board[0].size();
        if(i< 0 || j<0 || i >= r || j>= c)
            return false;
        if(k== word.size())
            return true;
        if(board[i][j] == word[k])
        {
            char tmp = board[i][j];
            board[i][j] = '-1';
            bool a = dfs(board,word,i+1,j,k+1);
            //cout<<"\n A: "<<a <<" "<<board[i][j]<<" pos: "<<k;
            bool b = dfs(board,word,i,j+1,k+1);
            //cout<<"\n B: "<<a <<" "<<board[i][j]<<" pos: "<<k;
            bool c = dfs(board,word,i-1,j,k+1);
            //cout<<"\n C: "<<a <<" "<<board[i][j]<<" pos: "<<k;
            bool d = dfs(board,word,i,j-1,k+1);
            //cout<<"\n D: "<<a <<" "<<board[i][j]<<" pos: "<<k;
            board[i][j] = tmp;
            return (a||
                    b||
                    c||
                    d);   
        }
        else return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int r = board.size();
        int c = board[0].size();
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board,word,i,j,0)) return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
