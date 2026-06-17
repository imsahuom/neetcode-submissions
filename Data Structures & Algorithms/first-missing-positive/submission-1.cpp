class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> pres(n+2, 0);
        for(auto& a: nums){
            if (a > 0 && a < n+2) pres[a] = 1;
        }
        int ans = 1;
        for(int i=1; i<n+2; i++){
            if (pres[i] == 0) return i;
            else ans++;
        }
        return ans;
    }
};