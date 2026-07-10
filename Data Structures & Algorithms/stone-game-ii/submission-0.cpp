class Solution {
public:
    vector<vector<int>> dp, ndp; int n;
    int dfs(vector<int>& piles, int i, int M, int flag){
        if (i >= n) return 0;
        M = min(n, M);
        if (flag && dp[i][M] != -1) return dp[i][M];
        if (!flag && ndp[i][M] != -1) return ndp[i][M];
        if (flag){
            int ans = 0, sum = 0;
            for(int take = 1; take <= 2*M; take++){
                if (i + take > n) break;
                sum += piles[i + take - 1];
                ans = max(ans, sum + dfs(piles,i + take, max(take, M), 0));
            }
            return dp[i][M] = ans;
        }else{
            int ans = 1e9;
            for(int take = 1; take <= 2*M; take++){
                if (i + take > n) break;
                ans = min(ans, dfs(piles, i + take, max(take, M), 1));
            }
            return ndp[i][M] = ans;
        }
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(n, vector<int>(n+1, -1));
        ndp.resize(n, vector<int>(n+1, -1));
        return dfs(piles, 0, 1, 1);
    }
};