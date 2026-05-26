class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,int target, int curr, int i, vector<int>& ans){
        if (curr == target){res.push_back(ans); return;}
        else if (curr > target || i >= nums.size()) return;
        ans.push_back(nums[i]);
        helper(nums, target, curr + nums[i], i, ans);
        ans.pop_back();
        helper(nums, target, curr, i+1, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> ans;
       helper(nums, target, 0, 0, ans);
       return res;
    }
};