class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = 0;
        unordered_map<string, int> words;
        for(auto& w: wordDict){
            int k = w.size();
            m = max(m, k);
            words[w]++;
        }
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            string str = "";
            int l = 0;
            while (l <= m && i+l < n){
                str += s[i+l];
                if (words.count(str) && dp[i+l+1]){
                    dp[i] = 1;
                    break;
                }
                l++;
            }
        }
        // cout << m << " ";
        return dp[0] == 1;
    }
};
