class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            ans[(i+k)%n] = nums[i];
        }
        nums = ans;
    }
};