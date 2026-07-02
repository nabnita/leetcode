class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int ms=0;
        int cs=0;
        for(int i=0;i<k;i++){
            cs+=nums[i];
        }
        ms=cs;
        for(int i=k;i<nums.length;i++){
            cs+=nums[i] - nums[i-k];
            ms=Math.max(ms,cs);
        }
        double ans=(double)ms/k;
        return ans;
    }
}