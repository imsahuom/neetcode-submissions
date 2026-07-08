class Solution {
public:
    int n, total;
    vector<vector<int>> memo;
    int dfs(int i, int curr, vector<int>& sto){
        if (i >= n) return memo[i][curr + total] = abs(curr);
        if (memo[i][curr + total] != -1) return memo[i][curr + total];
        return memo[i][curr + total] = min(dfs(i+1, curr + sto[i], sto), dfs(i+1, curr-sto[i], sto));
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        total = 0;
        for(auto& x: stones) total += x;
        memo.assign(n+1, vector<int>(2*total + 1, -1));
        return dfs(0, 0, stones);
    }
};