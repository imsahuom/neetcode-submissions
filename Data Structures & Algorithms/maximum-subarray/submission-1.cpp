class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for(auto x: nums){
            ans = max(ans, sum + x);
            if (x + sum < 0) sum = 0;
            else {
                sum += x; 
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
