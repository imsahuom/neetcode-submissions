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
    unordered_map<TreeNode*, pair<int, int>> mp;
    int knapsack(TreeNode* node,bool last){
        if (node == nullptr) return 0;
        if (mp.count(node)){
            if (last && mp[node].first != -1) return mp[node].first;
            else if (!last && mp[node].second != -1) return mp[node].second; 
        }
        int ans = knapsack(node->left, true) + knapsack(node->right, true);//don't rob, so we can rob further for sure
        if (last){//we can rob this house;
            ans = max (ans, node->val + knapsack(node->left, false) + knapsack(node->right, false));
        }
        mp[node] = {-1, -1};
        if (last) return mp[node].first = ans;
        else return mp[node].second = ans;
    }
    int rob(TreeNode* root) {
        return knapsack(root, true);
    }
};