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
    vector<int> pre;
    void traverse(TreeNode* root){
        if (!root) return;
        traverse(root->left);
        pre.push_back(root->val);
        traverse(root->right);
    }
    bool isValidBST(TreeNode* root) {
        traverse(root);
        int n = pre.size();
        // for(auto x: pre) cout << x << " ";
        for(int i=1; i<n; i++){
            if (pre[i] <= pre[i-1]) return false;
        }
        return true;
    }
};