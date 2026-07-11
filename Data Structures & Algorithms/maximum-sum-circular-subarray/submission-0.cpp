class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, sum = 0, total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        int rem = INT_MAX; sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            rem = min(rem, sum);
            if (sum > 0) sum = 0;
        }
        // cout << rem << " " << total << " ";
        if (rem != total)
        ans = max(ans, total - rem);
        return ans;
    }
};