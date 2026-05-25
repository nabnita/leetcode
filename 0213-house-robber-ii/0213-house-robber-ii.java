class Solution {
    public int rob(int[] nums) {
        if(nums.length == 1){
            return nums[0];
        }
        return Math.max(
            robRange(nums,0,nums.length-2),
            robRange(nums,1,nums.length-1)
        );
    }
    public int robRange(int[] nums,int start,int end){
        int[] dp = new int[nums.length+2];
        for(int i=end;i>=start;i--){
            dp[i]= Math.max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[start];   
    } 
}