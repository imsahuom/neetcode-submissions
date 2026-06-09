class Solution {
public:
    int target = 0;
    vector<vector<int>> dp;
    bool select(vector<int>& nums, int i, int sum1){
        if (i >= nums.size()){
            return sum1 == target;
        }
        if (sum1 > target) return false;
        if (dp[i][sum1] != -1) return dp[i][sum1];
        dp[i][sum1] = (select(nums, i+1, sum1+nums[i]) || select(nums, i+1, sum1));
        return dp[i][sum1];
    }
    bool canPartition(vector<int>& nums) {
        for(auto& x: nums) target += x;
        if (target%2 != 0) return false;
        target /= 2;
        dp.assign(nums.size()+3, vector<int>(target+3, -1));
        return select(nums, 0, 0);
    }
};