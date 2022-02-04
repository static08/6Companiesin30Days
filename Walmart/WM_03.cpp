#  Remove Colored Pieces if Both Neighbors are the Same Color
class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0,bob = 0;
        int i = 0;
        while(i < colors.size())
        {
            int cA = 0,cB = 0;
            if(colors[i] == 'A')while(colors[i] == 'A' and i < colors.size()){cA++;i++;}
            else while(colors[i] == 'B' and i < colors.size()){cB++;i++;}
            if(cA > 2)alice += cA-2;
            else if(cB > 2)bob += cB-2;
        }
        return alice > bob;
    }
};
