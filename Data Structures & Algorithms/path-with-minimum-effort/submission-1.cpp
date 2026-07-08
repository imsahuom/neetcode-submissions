class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> adj(n*m);//n*m points, every point is m*i + j ???
        //m*(n-1) + (m-1) = m*n - m + m - 1 = m*n - 1 th node is our target
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (i-1 >= 0) adj[m*i + j].push_back({m*(i-1) + j ,abs(grid[i][j] - grid[i-1][j])});
                if (j-1 >= 0) adj[m*i + j].push_back({m*i + (j-1), abs(grid[i][j] - grid[i][j-1])});
                if (i+1 < n) adj[m*i + j].push_back({m*(i+1) + j, abs(grid[i][j] - grid[i+1][j])});
                if (j+1 < m) adj[m*i + j].push_back({m*i + j + 1, abs(grid[i][j] - grid[i][j+1])});
            }
        }
        //now just run dijsktra with source 0, and sink m*n - 1
        //we've our adj list :)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({0, 0});
        vector<int> visit(m*n, 0);
        vector<int> dist(m*n, 1e9); dist[0] = 0;
        while(!pq.empty()){
            auto [path, node] = pq.top(); pq.pop();
            if (visit[node]) continue;
            visit[node] = 1;
            for(auto& [x, d]: adj[node]){
                if (dist[x] > max(path, d)){
                    dist[x] = min(dist[x], max(path, d));   
                    pq.push({dist[x], x});
                }
                
            }
        }
        return dist[m*n-1];
    }
};