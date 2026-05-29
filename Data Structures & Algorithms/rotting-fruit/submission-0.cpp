class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = 0, time = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }else if (grid[i][j] == 1){
                    total++;
                }
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if ( nx<0 || ny<0 || nx >= n|| ny >= m || grid[nx][ny] != 1) continue;
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
                total--;
            }
            time = max(time, grid[x][y] - 2);
        }
        if (total > 0) return -1;
        return time;
    }
};
