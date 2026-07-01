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
    map<pair<TreeNode*, bool>, int> mp;
    int knapsack(TreeNode* node,bool last){
        if (node == nullptr) return 0;
        if (mp.count({node, last})) return mp[{node, last}];
        int ans = knapsack(node->left, true) + knapsack(node->right, true);//don't rob, so we can rob further for sure
        if (last){//we can rob this house;
            ans = max (ans, node->val + knapsack(node->left, false) + knapsack(node->right, false));
        }
        return mp[{node, last}] = ans;
    }
    int rob(TreeNode* root) {
        return knapsack(root, true);
    }
};