# Divide Two Integers
class Solution {
public:
    int divide(int dividend, int divisor) {
            
            if(dividend==divisor)
                    return 1;
             int sign=(dividend>=0&&divisor>=0)||(dividend<0&&divisor<0)?1:-1;

            unsigned int dividendAbsValue=abs(dividend);
            unsigned int divisorAbsValue=abs(divisor);
            unsigned int quotient=0;

            while(dividendAbsValue>=divisorAbsValue)
            {
                    int countShiftLeft=0;
                    while(dividendAbsValue>(divisorAbsValue<<(countShiftLeft+1)))
                            countShiftLeft++;
                    quotient+=1<<countShiftLeft;
                    dividendAbsValue-=divisorAbsValue<<countShiftLeft;  
            }
            if(quotient==1<<31&&sign==1)
                    return INT_MAX;
            return quotient*sign;
                    
            
    }
};
