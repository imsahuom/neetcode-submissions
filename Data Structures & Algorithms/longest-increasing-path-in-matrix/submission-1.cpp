class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int n = v.size(), m = v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push({v[i][j], {i, j}});
            }
        }
        int maxi = 1;
        vector<vector<int>> explored(n, vector<int>(m, 0));
        while(!pq.empty()){
            auto [a, b] = pq.top();pq.pop();
            int x = b.first, y = b.second;
            maxi = max(maxi, dp[x][y]);
            if (explored[x][y]) continue;
            explored[x][y] = 1;
            // cout << a << "->";
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if (nx<0 || ny<0 || nx >= n || ny >= m || v[nx][ny] <= a) continue;
                dp[nx][ny] = max(dp[nx][ny], 1 + dp[x][y]);
                // cout << v[nx][ny] << "{" << dp[nx][ny] << "}, ";
                pq.push({v[nx][ny], {nx, ny}});
            }
        }
        return maxi;
    }
};
