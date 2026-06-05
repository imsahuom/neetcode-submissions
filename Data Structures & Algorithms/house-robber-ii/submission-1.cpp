class Solution {
public:
    int rob(vector<int>& nums) {
        //question is basically maximum we can get without choosing 0th and n-1th house
        int n = nums.size();
        if (n < 2) return nums[0];
        vector<int> dp(n+1, 0);
        dp[0] = 0;//don't choose 0th house
        dp[1] = nums[1];
        for(int i=2; i<n; i++){
            dp[i] = nums[i] + dp[i-2];
            dp[i] = max(dp[i], dp[i-1]);
        }
        int c1 = max(dp[n-1], dp[n-2]);
        nums[n-1] = 0;//don't choose last house
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i=2; i<n; i++){
            dp[i] = nums[i] + dp[i-2];
            dp[i] = max(dp[i], dp[i-1]);
        }
        return max(c1, max(dp[n-1], dp[n-2]));
    }
};
