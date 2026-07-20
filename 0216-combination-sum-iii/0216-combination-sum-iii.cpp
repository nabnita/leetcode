class Solution {
public:
    void solve(int i, int k, int n, int sum, vector<int> &temp, vector<vector<int>> &res){
        if(temp.size()==k){
            if(sum==n){
                res.push_back(temp);
            }
            return;
        }
        while(i<=9){
        if(sum+i <= n){
            temp.push_back(i);
            solve(i+1,k,n,sum+i,temp,res);
            temp.pop_back();
            }
            i++;
    }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1,k,n,0,temp,res);
        return res;
    }
};