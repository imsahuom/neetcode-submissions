class Solution {
public:
    int dfs(string& s, unordered_map<char, int>& st, unordered_map<string, int>& mp, int i, vector<int> &dp){
        if (i >= s.size()) return 0;
        //choice 1 skip
        int ans;
        if (dp[i+1] != s.size()) ans = 1 + dp[i+1];
        else{
            dp[i+1] = dfs(s, st, mp, i+1, dp);
            ans = 1 + dp[i+1];
        }
        if (st.find(s[i]) == st.end()) return ans; //we can't do anything
        int j = i;// to find s[i:j] exists??
        string curr = "";
        while(j < s.size()){
            curr += s[j];
            if (mp.find(curr) != mp.end()){
                //curr is a valid choice, so skip [i:j]
                if (dp[j+1] == s.size()) dp[j+1] = dfs(s, st, mp, j+1, dp);
                ans = min(ans, dp[j+1]);
            }
            j++;
        }
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        vector<int> dp(s.size()+1, s.size());
        unordered_map<char, int> st;
        for(auto d: dictionary){
            mp[d]++;
            st[d[0]]++;
        }
        return dfs(s, st, mp, 0, dp);
    }
};