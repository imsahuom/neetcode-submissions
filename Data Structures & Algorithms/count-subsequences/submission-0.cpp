class Solution {
public:
    vector<vector<int>> memo;
    int dfs(string& s, string& t, int i, int j){
        if(j >= t.size()) return 1;
        else if(i >= s.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(s[i] == t[j]) ans += dfs(s, t, i+1, j+1);
        ans += dfs(s, t, i+1, j);
        return memo[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memo.assign(s.size()+1, vector<int>(t.size()+1, -1));
        return dfs(s, t, 0, 0);
    }
};
