class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& adj,string curr, string targ, string par, unordered_map<string, int>& visit){
        if (curr == targ) return 1.0;
        for(auto& [next, val]: adj[curr]){
            if (next == par || visit.count(next)) continue;
            visit[next]++;
            double m = dfs(adj, next, targ, curr, visit);
            if (m != -1) return val*m;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i=0; i<n; i++){
            string a = equations[i][0], b = equations[i][1];
            double d = values[i];
            //now a/b = d and b/a = 1/d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, (1.0)/d});
        }
        //for each query C, D we need to find out the value of path product from C to D, and -1 if not exist
        vector<double> ans;
        for(auto& q: queries){
            if (!adj.count(q[0]) || !adj.count(q[1])) ans.push_back(-1.0);
            else {
                unordered_map<string, int> mp;
                mp[q[0]]++;
                ans.push_back(dfs(adj, q[0], q[1], "1", mp));
            }
        }
        return ans;
    }
};