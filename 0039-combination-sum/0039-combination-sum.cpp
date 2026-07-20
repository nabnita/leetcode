class Solution {
public:
    void solve(int i, int n, int sum, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &res){
        if(sum==target){
            res.push_back(temp);
            return;}
        if(i>n-1 || target<sum){
            return;
        }
        temp.push_back(candidates[i]);
        solve(i,n,candidates[i] + sum,candidates,target,temp,res);
        temp.pop_back();
        solve(i+1,n,sum,candidates,target,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> res;
        solve(0,n,0,candidates,target,temp,res);
        return res;
    }
};