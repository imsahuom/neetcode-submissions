class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& a: nums) mp[a]++;
        vector<pair<int, int>> p;
        for(auto& [a, b]: mp) p.push_back({b, a});
        sort(p.rbegin(), p.rend());
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(p[i].second);
        }
        return ans;
    }
};
