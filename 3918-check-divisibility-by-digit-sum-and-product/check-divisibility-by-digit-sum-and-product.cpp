class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int mul=1;
        int k=n;
        while(k!=0){
            int rem=k%10;
            sum+=rem;
            mul*=rem;
            k/=10;
        }
        int sum2=sum+mul;
        if(n%sum2==0){
            return true;
        }
        else{
            return false;
        }
    }
};