class Solution {
public:
    int solve(int i, int n, vector<int>& nums, int sum, int target,
              vector<vector<int>> &dp) {
        if (sum == target) return 1;
        if (i >= n || sum > target) return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int pick = solve(i + 1, n, nums, sum + nums[i], target, dp);
        int not_pick = solve(i + 1, n, nums, sum, target, dp);
        return dp[i][sum] = pick || not_pick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, n, nums, 0, target, dp);
    }
};