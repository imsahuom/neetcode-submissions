class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mx){

        if(!root) return;

        if(root->val >= mx)
            ans++;

        mx = max(mx, root->val);

        dfs(root->left, mx);
        dfs(root->right, mx);
    }

    int goodNodes(TreeNode* root) {

        dfs(root, root->val);

        return ans;
    }
};