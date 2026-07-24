/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int &count, vector<int> &temp) {
        if(root == NULL)
            return;
        temp.push_back(root->val);
        solve(root->left, targetSum, count,temp);
        solve(root->right, targetSum, count,temp);
        long long sum=0;
        for(int i=temp.size()-1;i>=0;i--){
            sum+=temp[i];
            if(sum == targetSum){
                count++;
            }
        }
        temp.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int count = 0;
        solve(root, targetSum, count,temp);
        return count;
    }
};