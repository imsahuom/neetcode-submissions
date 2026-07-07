class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n = obs.size(), m = obs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            if (obs[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int j=0; j<m; j++){
            if (obs[0][j] == 1) break;
            dp[0][j] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if (obs[i][j] == 1) continue;
                if (obs[i][j-1] == 0) dp[i][j] += dp[i][j-1];
                if (obs[i-1][j] == 0) dp[i][j] += dp[i-1][j];
            }
        }
        // for(auto& x: dp){
        //     for(auto& y: x) cout << y << " "; cout << endl;
        // }
        return dp[n-1][m-1];
    }
};