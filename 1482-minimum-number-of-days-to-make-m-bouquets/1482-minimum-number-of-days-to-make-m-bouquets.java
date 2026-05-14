class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if((long)(m)*k>bloomDay.length){
            return -1;
        }
        int low=Integer.MAX_VALUE;
        int high=Integer.MIN_VALUE;
        for(int i=0;i<=bloomDay.length-1;i++){
            low=Math.min(low,bloomDay[i]);
            high=Math.max(high,bloomDay[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            int bouquet=0;
            int flowers=0;
            for(int i=0;i<bloomDay.length;i++){
                if(bloomDay[i]<=mid){
                    flowers++;
                    if(flowers==k){
                        bouquet++;
                        flowers=0;
                    }
                }
                else{
                    flowers=0;
                }
            }
            if(bouquet>=m){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
}