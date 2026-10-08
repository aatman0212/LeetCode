class Solution {
public:
    int find(int n,int t){
        int rem=n;
        int sum=1;
        while(rem!=0){
            int r=rem%10;
            sum*=r;
            rem/=10;
        }
        if(sum%t==0){
            return n;
        }
        else{
            return find(n+1,t);
        }
    }
    int smallestNumber(int n, int t) {
        return find(n,t);
    }
};