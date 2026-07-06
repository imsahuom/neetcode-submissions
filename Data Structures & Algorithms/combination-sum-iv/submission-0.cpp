class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& nums, int t){
        if (t <= 0) return 1;
        if (memo[t] != -1) return memo[t];
        int ans = 0;
        for(auto& n: nums){
            if (t - n >= 0) ans += dp(nums, t - n); 
        }
        return memo[t] = ans;
    }
    int combinationSum4(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        memo.assign(t+1, -1);
        memo[0] = 1;
        return dp(nums, t);
    }
};