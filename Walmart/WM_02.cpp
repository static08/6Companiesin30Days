# Stone Game
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dpAlex(n, vector<int>(n, 0));
        vector<vector<int>> dpLee(n, vector<int>(n, 0));
        dpAlex[n-1][n-1] = piles[n-1];
        dpLee[n-1][n-1] = -piles[n-1];
        dpAlex[0][0] = piles[0];
        dpLee[0][0] = -piles[0];

        for(int i = n-2; i>=0;i--){
            for(int j =i; j<n ; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                dpAlex[i][j] = max(piles[i] + dpLee[i+1][j], piles[j] + dpLee[i][j-1]);
                dpLee[i][j] = min(-piles[i] + dpAlex[i+1][j], -piles[j] + dpAlex[i][j-1]);
            }
        }
        return dpAlex[0][n-1] > 0? true: false;
    }
    
};
