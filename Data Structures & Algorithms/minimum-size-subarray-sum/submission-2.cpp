class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum  = 0, n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if (sum < target) return 0;
        int ans = 0;
        while(ans < n){
            ans++;
            sum = 0;
            for(int i=0; i<ans; i++) sum += nums[i];
            int idx = ans;
            while(idx < n && sum < target){
                sum += (nums[idx] - nums[idx - ans]);
                idx++;
                if(sum >= target) return ans;
            }
            if(sum >= target) return ans;
        }
        return ans;
    }
};