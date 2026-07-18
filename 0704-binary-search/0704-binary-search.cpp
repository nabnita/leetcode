class Solution {
public:
    int helper(int l , int r , vector<int>& nums , int target){
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            return helper(mid+1,r,nums,target);
        }
        else if(nums[mid] > target){
            return helper(l,mid-1,nums,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r= nums.size()-1;
        return helper(l,r,nums,target);
    }
};