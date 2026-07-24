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
    void solve(TreeNode* root,vector<int> temp , int targetSum, int sum,vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum + root->val ==targetSum){
                ans.push_back(temp);
            }
        }
        solve(root->left,temp,targetSum,sum+root->val,ans);
        solve(root->right,temp,targetSum,sum+root->val,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root,temp,targetSum,0,ans);
        return ans;
    }
};