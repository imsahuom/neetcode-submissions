class Solution {
public:
    int n;
    vector<int> memo;
    
    int amnt(vector<int>& nums, int h){
        if (h >= n) return 0;
        if (memo[h] != -1) return memo[h];
        int cost1 = nums[h] + amnt(nums, h+2);
        int cost2 = amnt(nums, h+1);
        return memo[h] = max(cost1, cost2);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        memo.resize(n+3, -1);
        return amnt(nums, 0);
    }
};
