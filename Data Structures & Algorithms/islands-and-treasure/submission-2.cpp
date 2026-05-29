class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int d=0; d<4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if (nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny] != INF)continue;
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};
