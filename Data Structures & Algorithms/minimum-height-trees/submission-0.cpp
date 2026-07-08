class Solution {
public:
    int dfs(vector<vector<int>>& adj, int i, int p){
        int h = 0;
        for(auto& x: adj[i]){
            if (x == p) continue;
            h = max(h, 1 + dfs(adj, x, i));
        }
        return h;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> hei(n+1);
        vector<vector<int>> adj(n+1);
        for(auto& v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i=0; i<n; i++){
            hei[dfs(adj, i, -1)].push_back(i);
        }
        for(auto& x: hei){
            if (x.size() != 0) return x;
        }
        return {};
    }
};