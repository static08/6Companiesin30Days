/* Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.(Modified version of question named Cute Monkeys) */

string encode(string src)
{     
    string ans = "";
    int i=1;
    int c =1;
    int n = src.size();
    
    while(i<n)
    {
        if(src[i-1]==src[i])
            c++;
            
        else{
            ans += src[i-1];
            ans += (c+'0');
            c=1;
        }
        
        i++;
    }
    
    ans += src[i-1];
    ans += (c+'0');
    
    return ans;
    
}     
