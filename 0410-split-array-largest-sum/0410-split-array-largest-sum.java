class Solution {
    public int splitArray(int[] nums, int k) {
        int high=0;
        int low=0;
        for(int i=0;i<nums.length;i++){
            low= Math.max(low,nums[i]);
            high+=nums[i];
        }
        while(low<high){
            int mid= low+(high-low)/2;
            int count=1;
            int sum=0;
            for(int i=0;i<nums.length;i++){
                if(nums[i]+sum>mid){
                    count++;
                    sum=nums[i];
                }
                else{
                    sum+=nums[i];
                }
            }
            if(count<=k){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
}