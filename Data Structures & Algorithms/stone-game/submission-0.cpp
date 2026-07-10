class Solution {
public:
    vector<vector<vector<int>>> memo;
    int dfs(vector<int>& piles, int i, int j, int flag){
        if (i > j) return 0;
        if (memo[i][j][flag] != -1) return memo[i][j][flag];
        if (flag){
            //Alice's turn
            return memo[i][j][flag] = max(piles[i] + dfs(piles, i+1, j, 0),piles[j] + dfs(piles, i, j-1, 0));
        }else
        return memo[i][j][flag] = max(dfs(piles, i+1, j, 1), dfs(piles, i, j-1, 1));
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0, n = piles.size();
        memo.assign(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2, -1)));
        for(auto& x: piles) total+=x;
        int a = dfs(piles, 0, piles.size()-1, 1);
        return (a > total/2);
    }
};