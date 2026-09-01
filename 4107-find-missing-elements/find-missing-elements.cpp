class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(min>nums[i]){
                min=nums[i];
            }
            if(max<nums[i]){
                max=nums[i];
            }
        }
        vector<int> number;
        for(int i=min;i<=max;i++){
            number.push_back(i);
        }
        for(int i=min;i<=max;i++){
            for(int j=0;j<nums.size();j++){
                if(i==nums[j]){
                    erase(number,i);
                }
            }
        }
        return number;
        
    }
};