class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int j=0; j<n; j++){
            sum += nums[j];
            //find no. of i's such that pre[i] = pre[j+1] - k;
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};