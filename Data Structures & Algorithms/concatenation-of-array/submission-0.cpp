class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans=nums;
        for(auto&a: nums) ans.push_back(a);
        return ans;
    }
};