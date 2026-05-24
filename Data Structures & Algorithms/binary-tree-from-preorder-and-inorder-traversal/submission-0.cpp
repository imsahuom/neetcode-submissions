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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        int r = preorder[0];
        TreeNode* root = new TreeNode(r);
        vector<int> p1, i1, p2, i2;
        for(auto x: inorder){
            if (x == r) break;
            i1.push_back(x);
        }
        int ls = i1.size(), rs = preorder.size() - ls - 1;
        for(int i=0; i<ls; i++){
            p1.push_back(preorder[i+1]);
        }
        for(int i = ls+1; i<preorder.size(); i++){
            i2.push_back(inorder[i]);
            p2.push_back(preorder[i]);
        }
        root->left = buildTree(p1, i1);
        root->right = buildTree(p2, i2);
        return root;
    }
};