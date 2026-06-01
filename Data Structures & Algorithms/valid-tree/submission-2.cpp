class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, -1);
        vector<vector<int>> adj(n);
        for(auto e: edges){
            if (e[0] == e[1]) return false;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int t = 0;
        queue<int> q;
        q.push(0);
        visited[0] = 0;
        while(!q.empty()){
            int e = q.front(); q.pop();
            t++;
            // cout << e << " ";
            for(auto x: adj[e]){
                if (visited[x] == -1){
                    visited[x] = e;//e is the parent of x
                    q.push(x);
                }else if (visited[x] != -1 && visited[e] != x){
                    // cout << visited[e] <<  " " << x << " "; 
                    return false;
                }
            }
        }
        if (t != n) return false;
        return true;
    }
};
