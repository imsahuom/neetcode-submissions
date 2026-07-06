class Solution {
public:
    unordered_map<int, int> ma, mb;
    int dfs1(int i, vector<int>& s, int n){
        //this will tell us how much alice can get max, 
        if (i >= n) return 0;
        if (ma.count(i)) return ma[i];
        int ans = s[i] + dfs2(i+1, s, n);
        if (i + 1 < n) ans = max(ans, s[i] + s[i+1] + dfs2(i+2, s, n));
        if (i + 2 < n) ans = max(ans, s[i] + s[i+1] + s[i+2] + dfs2(i+3, s, n));
        return ma[i] = ans;
    }
    int dfs2(int i, vector<int>& s, int n){
        //this will tell how much alice can get min, like bob will try that
        if (i >= n) return 0;
        if (mb.count(i)) return mb[i];
        int ans = dfs1(i+1, s, n);
        if (i + 1 < n) ans = min(ans, dfs1(i+2, s, n));
        if (i + 2 < n) ans = min(ans, dfs1(i+3, s, n));
        return mb[i] = ans;
    }
    string stoneGameIII(vector<int>& s) {
        int total = 0;
        for(auto& x: s) total += x;
        int a = dfs1(0, s, s.size());
        int b = total - a;
        if (a > b) return "Alice";
        else if (b > a) return "Bob";
        return "Tie";
    }
};