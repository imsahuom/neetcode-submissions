class Solution {
public:
    vector<vector<int>> mp;
    bool help(string& s1, string& s2, string& s3, int i1, int i2, int i3){
        if (i3 >= s3.size() && i1 >= s1.size() && i2 >= s2.size()) return 1;
        else if (i1 >= s1.size() && i2 >= s2.size()) return 0;
        if (mp[i1][i2] != -1) return mp[i1][i2];
        int ans = 0;
        if (i1 >= s1.size()){
            if (s2[i2] == s3[i3]) ans += help(s1, s2, s3, i1, i2+1, i3+1);
        }else if (i2 >= s2.size()){
            if (s1[i1] == s3[i3]) ans += help(s1, s2, s3, i1+1, i2, i3+1);
        }else{
            if (s2[i2] == s3[i3]) ans += help(s1, s2, s3, i1, i2+1, i3+1);
            if (s1[i1] == s3[i3]) ans += help(s1, s2, s3, i1+1, i2, i3+1);
        }
        return mp[i1][i2] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2. size();
        if (n + m != s3.size()) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if (i == 0 && j == 0) continue;
                int x = 0;
                if (i-1 >= 0 && s1[i-1] == s3[i+j-1]) x += dp[i-1][j];
                if (j-1 >= 0 && s2[j-1] == s3[i+j-1]) x += dp[i][j-1];
                dp[i][j] = (x>0) ? 1 : 0;
            }
        }
        return dp[n][m] == 1;
    }
};