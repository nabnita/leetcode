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
    int solve(TreeNode* root, long long targetSum, long long sum) {
        if(root == NULL)
            return 0;
        sum += root->val;
        int count = 0;
        if(sum == targetSum)
            count++;
        count += solve(root->left, targetSum, sum);
        count += solve(root->right, targetSum, sum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        return solve(root, targetSum, 0) + pathSum(root->left, targetSum)+ pathSum(root->right, targetSum);
    }
};