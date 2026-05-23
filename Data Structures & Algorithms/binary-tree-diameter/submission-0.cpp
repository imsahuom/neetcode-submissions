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
    int height(TreeNode* root){
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameter(TreeNode* root,int ans){
        if (!root) return ans;
        ans = max(ans, height(root->left) + height(root->right));
        ans = max(ans, diameter(root->left, ans));
        return max(ans, diameter(root->right, ans));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root, 0);
    }
};
