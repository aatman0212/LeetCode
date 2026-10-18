class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        int p=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<k){
            return sum;
        }
        if(sum%k==0){
            return 0;
        }
        while(sum%k!=0){
            p++;
            sum-=1;
        }
        return p;
    }
};