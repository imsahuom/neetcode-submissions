class Solution {
public:
    int numSquares(int n) {
        vector<int> bag;
        for(int i=1; i<=100; i++) bag.push_back(i*i);
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(auto& c: bag){
                if (c > i) break;
                dp[i] = min(dp[i],1 + dp[i-c]);
            }
        }
        return dp[n];
    }
};