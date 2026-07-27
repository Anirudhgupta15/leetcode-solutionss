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
    int sumNumbers(TreeNode* root){
        return dfs(root, 0);
        } 
    
private:
    int dfs(TreeNode* root, int currentSum) {
        if (root == nullptr) return 0;       
        currentSum = currentSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return currentSum;
        return dfs(root->left, currentSum) + dfs(root->right, currentSum);
    }
};