class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0|| ny<0||nx>=grid.size()||ny>=grid[0].size()||grid[nx][ny] != '1')continue;
            dfs(grid, nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        grid[x][y] = '0';
                        for(int k=0; k<4; k++){
                            int nx = x + dx[k], ny = y + dy[k];
                            if(nx < 0|| ny<0||nx>=grid.size()||ny>=grid[0].size()||grid[nx][ny] != '1')continue;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};