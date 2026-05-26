class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& curr, int start){
        res.push_back(curr);
        for(int i=start; i<nums.size(); i++){
            if (i-1 >= 0 && nums[i] == nums[i-1] && i!= start) continue;
            curr.push_back(nums[i]);
            backtrack(nums, curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(nums, curr, 0);
        return res;
    }
};