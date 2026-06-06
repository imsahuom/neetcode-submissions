class Solution {
public:
    vector<int> dp;

    int combs(vector<int>& coins, int target, int sum){
        if (sum == target) return dp[sum] = 0;
        else if (sum > target) return -1;
        if (dp[sum] != 0) return dp[sum];
        int ans = 1e9;
        for(auto& c: coins){
            if (c > target - sum) continue;
            int k = combs(coins, target, sum + c);
            if ( k!= -1){
                ans = min(ans,1 + k);
            }
        }
        if (ans != 1e9)dp[sum] = ans;
        else dp[sum] = -1;
        return dp[sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+2, 0);
        return combs(coins, amount, 0);
    }
};
