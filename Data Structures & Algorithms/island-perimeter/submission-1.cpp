class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //for each island, we can have 0/1/2/4 contribution for the peri
        //so we'll do BFS, for each curr, we'll check eligible, and add
        int n = grid.size(), m = grid[0].size();
        pair<int, int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    st = {i, j};
                    break;
                }
            }
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push(st);
        visited[st.first][st.second] = 1;
        int ans = 0;
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            int score = 4;
            if (x-1>=0 && grid[x-1][y] == 1){
                score--;
                if (visited[x-1][y] == 0){
                    q.push({x-1, y});
                    visited[x-1][y] = 1;
                }
            }
            if (x+1<n && grid[x+1][y] == 1){
                score--;
                if (visited[x+1][y] == 0){
                    q.push({x+1, y});
                    visited[x+1][y] = 1;
                }
            }
            if (y-1 >=0 && grid[x][y-1] == 1){
                score--;
                if (visited[x][y-1] == 0){
                    q.push({x, y-1});
                    visited[x][y-1] = 1;
                }
            }
            if (y+1 < m && grid[x][y+1] == 1){
                score--;
                if (visited[x][y+1] == 0){
                    q.push({x, y+1});
                    visited[x][y+1] = 1;
                }
            }
            ans+=score;
        }
        return ans;
    }
};