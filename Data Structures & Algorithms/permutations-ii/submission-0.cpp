class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums ,vector<int>& curr, int n){
        if (curr.size() == n){ans.push_back(curr); return;}
        for(int i=0; i<n; i++){
            if (nums[i] == -1) continue;
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
            curr.push_back(nums[i]);
            nums[i] = -1;
            dfs(nums, curr, n);
            nums[i] = curr.back();
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr; int n = nums.size();
        curr.reserve(n);
        dfs(nums, curr, n);
        return ans;
    }
};