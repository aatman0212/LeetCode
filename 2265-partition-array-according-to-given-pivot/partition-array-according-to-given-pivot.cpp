class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                more.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                count++;
            }
        }
        while(count!=0){
            less.push_back(pivot);
            count--;
        }
        for(int i=0;i<more.size();i++){
            less.push_back(more[i]);
        }
        return less;
    }
};