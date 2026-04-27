class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] arr= new int[n];
        int left = 0;
        int right = n-1;
        int index = n-1;
        while(left<=right){
            if(Math.abs(nums[left])> Math.abs(nums[right])){
                arr[index] = nums[left]*nums[left];
                left++;
            }
            else{
                arr[index] = nums[right]*nums[right];
                right--;
            }
            index--;
        }
        return arr;
    }
}