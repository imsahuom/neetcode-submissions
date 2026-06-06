class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //this is a subsequence problem not the subarray
        int n = nums.size();
        vector<int> mp(n), p(n);
        mp[0] = nums[0];
        p[0] = nums[0];
        int ans = nums[0];
        for(int i=1; i<n; i++){
            int mini = nums[i]*p[i-1], maxi = nums[i]*mp[i-1];
            if (mini > maxi) swap(mini, maxi);
            ans = max(ans, max(maxi, nums[i]));
            mp[i] = max(maxi, nums[i]);
            p[i] = min(mini, nums[i]);
        }
        ans = max(ans, mp[n-1]);
        return ans;
    }
};