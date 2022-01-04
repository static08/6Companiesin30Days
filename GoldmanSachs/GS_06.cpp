/*  Given two strings str1 and str2. We say that str2 divides str1 if it's possible to          
concatenate multiple str2 to get str1. For example, ab divides abab 
if str2 does not divide str1, return -1. Otherwise, return the smallest string
str3 such that str3 divides both str1 and str2.*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        if(str1 == str2){
            return str1;
        }
        int n = min(l1, l2); 
        int flag = 1;
        while(n){
            if(l1%n==0 && l2%n==0){    
                string gcd = str1.substr(0,n);
                for(int i =0;i<str1.size();i+= n){
                    if(str1.substr(i,n)!= gcd){
                        flag = 0;
                        break;
                    }
                }
                if(flag==1){
                    for(int i =0;i<str2.size();i+= n){
                        if(str2.substr(i,n)!= gcd){
                            flag = 0;;
                            break;
                        }
                    }
                }
                if(flag==1){
                    return gcd;
                }
            }
            n--;
        }
        return "";
    }
};
