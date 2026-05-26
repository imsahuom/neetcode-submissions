class Solution {
public:
    vector<vector<int>> res;
    void back(vector<int>& nums, vector<int>& curr,unordered_map<int, int>& used, int i){
        if (i >= nums.size()){res.push_back(curr); return;}
        for(auto n: nums){
            if(!used[n]){
                curr.push_back(n);
                used[n]++;
                back(nums, curr, used, i+1);
                used[n]--;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> curr;
        back(nums, curr, mp, 0);
        return res;
    }
};