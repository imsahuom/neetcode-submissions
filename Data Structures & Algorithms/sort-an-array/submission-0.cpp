class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& a: nums) pq.push(a);
        vector<int> ans;
        int n = pq.size();
        while(n--){ans.push_back(pq.top()); pq.pop();}
        return ans;
    }
};