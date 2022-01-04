/*Given a pattern containing only I's and D's. I for increasing and D for decreasing.Devise an algorithm to print the minimum number following that pattern.*/

class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.size();
        vector<int> sol;
        int min_num = 1, nearI = 0;
        
        if(S[0] == 'I'){
            sol.push_back(1);
            sol.push_back(2);
            min_num = 3;
            nearI =1;
        }
        
        else{
            sol.push_back(2);
            sol.push_back(1);
            min_num = 3;
            nearI = 0;
        }
        
        for(int i=1; i<n; i++)
        {
            if(S[i] == 'I')
            {
                sol.push_back(min_num++);
                nearI = i+1;
            }
            else
            {
                sol.push_back(sol[i]);
                for(int j =nearI; j<=i; j++)
                    sol[j]++;
                    
                min_num++;
            }
        }
        
        string ans = "";
        
        for(int i=0; i< sol.size(); i++)
            ans +=  sol[i] + '0';
            
        return ans;
    }
};
