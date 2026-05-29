class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void solve(vector<vector<char>>& board) {
        //so basically bfs from all the border O's and rest O's will be X automatically :)
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){//from top layer wisit all the sluts;
            if (board[i][0] == 'O' && visited[i][0] == 0){
                visited[i][0] = 1;
                q.push({i, 0});
                
            }
            if (board[i][m-1] == 'O' && visited[i][m-1] == 0){
                visited[i][m-1] = 1; //from bottom layer
                q.push({i, m-1});
            }
        }
        for(int i=0; i<m; i++){
            if (board[0][i] == 'O' && visited[0][i] == 0){
                visited[0][i] = 1;//from left border
                q.push({0, i});
            }
            if (board[n-1][i] == 'O' && visited[n-1][i] == 0){
                visited[n-1][i] = 1;//from right border
                q.push({n-1, i});
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int k=0; k<4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if (nx<0 || ny<0 || nx>=n || ny>= m || visited[nx][ny] == 1 || board[nx][ny] == 'X') continue;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};