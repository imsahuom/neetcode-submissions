class Solution {
public:
    unordered_map<int, int> mp;
    int dfs(int n){
        if (n <= 4) return mp[n] = n;
        if (mp.count(n)) return mp[n];
        return mp[n] = 3*dfs(n-3);
    }
    int integerBreak(int n) {
        if (n <= 5){
            return ((n-n/2) * (n/2));
        }
        return 3*dfs(n-3);
    }
};