class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left =0;
        int right=0;
        for(int i=0;i<weights.length;i++){
            left=Math.max(left,weights[i]); //max weight in the array
            right+= weights[i]; //sum of all the weight/load of the array
        }
        int ans=right;
        while(left<=right){
            int mid= left+(right-left)/2;
            int neededDays = 1;
            int load = 0;
            for(int i=0;i<weights.length;i++){
                if(load + weights[i] > mid){
                    neededDays++;
                    load=weights[i];
                }
                else{
                    load+=weights[i];
                }}
                if(neededDays <= days){
                    ans=mid;
                    right=mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        
        return ans;
    }
}