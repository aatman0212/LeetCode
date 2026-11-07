class Solution {
public:
    int mirrorDistance(int n) {
        int m=n;
        int k=0;
        while(m!=0){
            int rem=m%10;
            m/=10;
            k=k*10+rem;
        }
        return abs(k-n);
    }
};