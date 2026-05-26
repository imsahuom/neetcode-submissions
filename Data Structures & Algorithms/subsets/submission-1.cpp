class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums, int i, vector<int>& curr) {
        // Base case: we've made a decision for every element
        if (i >= nums.size()) {
            ans.push_back(curr); // This is the only time we copy the vector
            return;
        }
        
        // Branch 1: Exclude nums[i]
        helper(nums, i + 1, curr);
        
        // Branch 2: Include nums[i]
        curr.push_back(nums[i]);     // Make the choice
        helper(nums, i + 1, curr);   // Explore with the choice
        curr.pop_back();             // Undo the choice (Backtrack)
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        // Reserve memory for 2^N subsets to avoid reallocation overhead (optional but good practice)
        ans.reserve(1 << nums.size()); 
        helper(nums, 0, curr);
        return ans;
    }
};