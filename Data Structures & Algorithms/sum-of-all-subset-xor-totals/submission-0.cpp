class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, int i, int curr){
        if (i >= nums.size()) {ans+=curr; return;}
        dfs(nums, i+1, curr);//use this no. 
        dfs(nums, i+1, curr^nums[i]);//don't use this no.
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ans;
    }
};