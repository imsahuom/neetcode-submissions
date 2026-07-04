class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& curr, int& n, int& k, int i){
        if (curr.size() == k){ ans.push_back(curr); return;}
        if (i > n) return;
        //we've two choices 1. leave i as it is
        dfs(curr, n, k, i+1);
        //2. put i in curr
        curr.push_back(i);
        dfs(curr, n, k, i+1);
        curr.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(curr, n, k, 1);
        return ans;
    }
};