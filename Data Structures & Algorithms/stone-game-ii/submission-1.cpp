class Solution {
public:
    vector<vector<int>> dp; int n, total;
    vector<int> pre;
    int dfs(vector<int>& piles, int i, int M){
        if (i >= n) return 0;
        M = min(M, n);
        if (dp[i][M] != -1) return dp[i][M];
        int ans = 0;
        int sum = 0;
        for(int take = 1; take<= 2*M; take++){
            if (i + take > n) break;
            sum += piles[i+take-1];
            ans = max(ans,sum + (total - pre[i+take] - dfs(piles, i+take, max(M, take))));//take ith pile for himself, 
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();total = 0;
        pre.resize(n+1, 0);
        for(int i=0; i<n; i++){
            pre[i+1] = piles[i] + pre[i];
            total += piles[i];
        }
        dp.resize(n, vector<int>(n+1, -1));
        return dfs(piles, 0, 1);
    }
};