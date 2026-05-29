class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int INF = 2147483647;
    void bfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        int scr = 0;
        while(!q.empty()){
            int k = q.size();
            scr++;
            while(k--){
                auto [x, y] = q.front(); q.pop();
                for(int d=0; d<4; d++){
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size()||grid[nx][ny] <= scr)continue;
                    grid[nx][ny] = scr;
                    q.push({nx, ny});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 0){
                    bfs(grid, i, j);
                }
            }
        }
    }
};
