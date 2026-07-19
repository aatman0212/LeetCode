class Solution {
public:
    int find(vector<int>& nums,int left,int right,int target){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if( nums[mid]<target){
                return find(nums,mid+1,right,target);
            }
            else{
                return find(nums,left,mid-1,target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ans=find(nums,0,nums.size()-1,target);
        return ans;
    }
};