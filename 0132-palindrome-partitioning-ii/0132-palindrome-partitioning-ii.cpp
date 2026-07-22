class Solution {
public:
    bool IsPalindrome(int i, int j, string &s){
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s, vector<int> &dp){
        if (i >= s.size()) {
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int cut = INT_MAX;
        for(int j = i; j < s.length(); j++){
            if(IsPalindrome(i,j,s)){
                cut=min(cut,1+solve(j+1,s,dp));
            }
        }
        dp[i] = cut;
        return dp[i];
    }
    int minCut(string s) {
        vector<int> dp(s.length()+1,-1);
        int i;
        return solve(0,s,dp)-1;
    }
};