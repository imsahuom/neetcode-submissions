class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& v: times){
            adj[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> distance(n+1, 1000000);
        q.push({0, k});
        distance[k] = 0;
        int ans = 0;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                auto [cd, curr] = q.top(); q.pop();
                // cout << distance[curr] << " ";
                for(auto& [si, di]: adj[curr]){
                    if (distance[si] > di + distance[curr]){
                        distance[si] = di + distance[curr];
                        q.push({distance[si], si});
                    }
                }
            }
            // cout << endl;
        }
        distance[0] = 0;
        for(auto& d: distance){//to check whether all nodes are reachable or not
            if (d >= 1000000) return -1;
            ans = max(ans, d);
        }
        return ans;
    }
};