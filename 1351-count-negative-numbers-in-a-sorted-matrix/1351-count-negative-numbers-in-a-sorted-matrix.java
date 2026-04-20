class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        int i= m-1;
        int j=0;
        while(j<n && i>= 0){
            if(grid[i][j] <0){
                count += n-j;
                i--;
            }
            else{
                j++;
            }
        }
        return count;
    }
}