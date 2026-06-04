class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        distance[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()){
            auto v = pq.top(); pq.pop(); int h = v[0], x = v[1], y = v[2];
            if (visited[x][y]) continue;

            visited[x][y] = 1;
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];

                if (nx<0 || ny<0 || nx>=n|| ny>=n) continue;
                if (distance[nx][ny] > max(h, grid[nx][ny])){
                    distance[nx][ny] = max(h, grid[nx][ny]);
                    pq.push({distance[nx][ny], nx, ny});
                }
            }
        }
        return distance[n-1][n-1];
    }
};
