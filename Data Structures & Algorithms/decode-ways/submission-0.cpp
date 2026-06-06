class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] == '0') ? 0 : 1;
        for(int i = n-2; i>=0; i--){
            if (s[i] == '0') continue;
            int k = s[i] - '0';
            if (k > 2 && s[i+1] == '0') return 0;
            if ( k > 2 || (k == 2 && s[i+1]-'0' > 6)){
                dp[i] = dp[i+1];
            }else if (s[i+1] == '0'){
                dp[i] = dp[i+2];
            }else{
                dp[i] = dp[i+1] + dp[i+2];
            }
        }
        return dp[0];
    }
};