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
    int maxi = -1e9;
    int maxpath(TreeNode* root){
        if (!root) return 0;
        int n = root->val;
        int r = maxpath(root->right);
        int l = maxpath(root->left);
        maxi = max(max(maxi, n), max(n+r, n+l));
        maxi = max(maxi, n + r + l);
        return max(n,n +  max(r, l));
    }
    int maxPathSum(TreeNode* root) {
        maxpath(root);
        return maxi;
    }
};
