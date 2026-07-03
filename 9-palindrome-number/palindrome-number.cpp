class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int c=x;
        long long p=0;
        while(c!=0){
            int rem=c%10;
            p=p*10+rem;
            c/=10;
        }
        if(p==x){
            return true;
        }
        else{
            return false;
        }
    }
};