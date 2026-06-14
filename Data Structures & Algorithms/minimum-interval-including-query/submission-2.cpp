class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> qs;
        for(int i=0; i<queries.size(); i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());
        //If I got [l, r] the best ans till r is min(ans, r) there 
        vector<int> ans(qs.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for(auto& [q, idx]: qs){
            while (i<n && intervals[i][0] <= q){
                pq.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                i++;
            }
            while (!pq.empty()){
                auto [s, r] = pq.top();
                if (r < q) pq.pop();
                else break;    
            }
            //no pq only have the useful intervals
            if(pq.empty()) ans[idx] = -1;
            else ans[idx] = pq.top().first;
        } 
        return ans;
    }
};