class Solution {
public:
    vector<vector<int>> res;
    
    void back(vector<int>& nums, int start) {
        // Base case: the "locked in" boundary reached the end
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);    // Make choice
            back(nums, start + 1);         // Recurse on the rest
            swap(nums[start], nums[i]);    // Undo choice (Backtrack)
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        back(nums, 0);
        return res;
    }
};