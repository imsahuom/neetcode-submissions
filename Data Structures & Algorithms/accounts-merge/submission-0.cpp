class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> adj;
        for(auto& x: accounts){
            auto u1 = x[1];
            int sz = x.size();
            for(int i=2; i<sz; i++){
                adj[x[i]].push_back(u1);
                adj[u1].push_back(x[i]);
            }
        }
        unordered_map<string, int> visited;
        vector<vector<string>> ans;
        for(auto& x: accounts){
            if (visited.count(x[1])) continue;
            vector<string> curr; curr.push_back(x[0]);
            queue<string> q;
            q.push(x[1]);
            visited[x[1]] = 1;
            while(!q.empty()){
                auto s = q.front(); q.pop();
                curr.push_back(s);
                for(auto& neigh: adj[s]){
                    if (visited.count(neigh)) continue;
                    visited[neigh]++;
                    q.push(neigh);
                }
            }
            sort(curr.begin()+1, curr.end());
            ans.push_back(curr);
        }
        return ans;
    }
};