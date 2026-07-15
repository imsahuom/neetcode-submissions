class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int l, int r){
        if (dp[l+1][r] != -1) return dp[l+1][r];
        int ans = 0;
        int left = 1;
        if (l != -1) left = nums[l];
        for(int i=l+1; i<r; i++){
            ans = max(ans, left*nums[i]*nums[r] + dfs(nums, l, i) + dfs(nums, i, r));
        }
        return dp[l+1][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+2, vector<int>(n+2, -1));
        nums.push_back(1);
        return dfs(nums, -1, n);
    }
};