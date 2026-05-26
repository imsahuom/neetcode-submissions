class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int i, vector<int> curr){
        if (i >= nums.size()){
            ans.push_back(curr);
            return;
        }
        helper(nums, i+1, curr);
        curr.push_back(nums[i]);
        helper(nums, i+1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(nums, 0, curr);
        return ans;
    }
};