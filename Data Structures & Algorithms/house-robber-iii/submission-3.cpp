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
    pair<int, int> dfs(TreeNode* node, bool flag){
        if (!node) return {0, 0};
        pair<int, int> l = dfs(node->left, true), r = dfs(node->right, true);
        int a1 = max(l.first, l.second) + max(r.first, r.second), a2 = node->val + l.first + r.first;
        return {a1, a2};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root, true);
        return max(ans.first, ans.second);
    }
};