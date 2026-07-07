class Solution {
    public int findNumbers(int[] nums) {
        int count =0;
        for(int num:nums){
            int temp=num;
            int digit=0;
            while(temp>0){
                temp/=10;
                digit++;
            }
            if(digit%2==0){
                    count++;
                }
        }
        return count;
    }
}