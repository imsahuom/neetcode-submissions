class Solution {
public:
    vector<vector<int>> dp;
    //dp[i][j] = max ans for dp[i][last]

    int dfs(vector<int>& nums,int i,int last){
        if (i >= nums.size()) return 0;
        if (dp[i][last+1000] != -1) return dp[i][last+1000];
        int k = dfs(nums, i+1, last);//ignore this shit
        if (last < nums[i]) k = max(k, 1 + dfs(nums, i+1, nums[i]));
        return dp[i][last+1000] = k;
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size()+3, vector<int>(2005, -1));
        return dfs(nums, 0, -1000);
    }

};
