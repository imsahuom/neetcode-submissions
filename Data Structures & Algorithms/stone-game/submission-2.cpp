class Solution {
public:
    vector<vector<int>> memo1, memo2;
    int dfs(vector<int>& piles, int i, int j, int flag){
        if (i > j) return 0;
        if (flag && memo1[i][j] != -1) return memo1[i][j];
        if (!flag && memo2[i][j] != -1) return memo2[i][j];
        if (flag){
            //Alice's turn
            return memo1[i][j] = max(piles[i] + dfs(piles, i+1, j, 0),piles[j] + dfs(piles, i, j-1, 0));
        }else
        return memo2[i][j] = min(dfs(piles, i+1, j, 1), dfs(piles, i, j-1, 1));
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0, n = piles.size();
        memo1.assign(n, vector<int>(n, -1));
        memo2.assign(n, vector<int>(n, -1));
        for(auto& x: piles) total+=x;
        int a = dfs(piles, 0, n-1, 1);
        return (a > total/2);
    }
};