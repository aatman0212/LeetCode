class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff=INT_MAX;
        int minsum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int s=nums[i]+ nums[left]+nums[right];
                if(s==target){
                    return s;
                }
                int diff=abs(target-s);
                if(mindiff>diff){
                    mindiff=diff;
                    minsum=s;
                }
                if(s>target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return minsum;
    }
};