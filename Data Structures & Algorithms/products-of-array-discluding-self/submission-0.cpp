class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> zeros;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0) zeros.push_back(i);
        }
        int m = 1;
        for(auto& a: nums){
            if (a == 0) continue;
            m *= a;
        }
        vector<int> ans(n, 0);
        if (zeros.size() >= 2) return ans;
        else if (zeros.size() == 1){
            ans[zeros[0]] = m;
            return ans;
        }else{
            for(int i=0; i<n; i++){
                ans[i] = m/nums[i];
            }
            return ans;
        }
        return ans;
    }
};
