class Solution {
public:
    int maxProduct(int n) {
        int m=0;
        int o=0;
        while(n!=0){
            int rem=n%10;
            if(rem>m && rem>o){
                o=m;
                m=rem;
            }
            else if(rem>o){
                o=rem;
            }
            n/=10;
        }
        return m*o;
    } 
};