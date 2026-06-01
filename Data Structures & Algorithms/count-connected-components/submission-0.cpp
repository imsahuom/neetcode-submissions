class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int st){
        for(auto x: adj[st]){
            if (visited[x] == 0){
                visited[x] = 1;
                dfs(adj, visited, x);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if (visited[i]==0){
                visited[i] = 1;
                ans++;
                dfs(adj, visited, i);
            }
        }
        return ans;
    }
};
