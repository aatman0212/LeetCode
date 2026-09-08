class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> number(nums.size()+1,0);
        for (int i=0;i<nums.size();i++){
            number[nums[i]]=1;
        }
        for(int i=0;i<number.size();i++){
            if(number[i]==0){
                return i;
            }
        }
        return -1;
    }
};