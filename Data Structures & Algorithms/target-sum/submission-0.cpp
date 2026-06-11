class Solution {
public:
    int ans = 0;
    void find(vector<int>& nums, int target, int i, int sum){
        if (i>= nums.size()){
            ans += (sum == target) ? 1 : 0;
            return;
        }
        find(nums, target, i+1, sum+nums[i]);
        find(nums, target, i+1, sum-nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        find(nums, target, 0, 0);
        return ans;
    }
};