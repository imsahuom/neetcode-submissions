class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0, n = nums.size();
        for(auto& x: nums) target += x;
        if (target%2 != 0) return false;
        target /= 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++){
            for(int j=target; j >=0; j--){
                if(j - nums[i] < 0) break;
                if (dp[j-nums[i]]) dp[j] = 1;
            }
        }
        return dp[target] == 1;
    }
};