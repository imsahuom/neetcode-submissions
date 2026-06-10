class Solution {
public:
    vector<vector<int>> memo;
    int market(vector<int>& prices, int day, int hold, int n){
        if (day >= n) return 0;

        if(hold >= 0 && memo[day][hold] != -1) return memo[day][hold];
        //we can just make our hold and ignore this day
        int ans = market(prices, day+1, hold, n);
        //so if hold >= n, we bought on (hold - n)th day
        if (hold >= n ){
            //we can sell, profit will be prices[day] - prices[hold-n]
            ans = max(ans, prices[day] - prices[hold-n] + market(prices, day+1, day, n));
        }
        //if hold <n, we sold last stock at hold th day, so we can sell if hold != day-1
        else if ( hold < n && hold < day-1){
            //we can buy here, then hold = n+day
            ans = max(ans, market(prices, day+1, n+day, n));
        }
        if (hold >= 0)  memo[day][hold] = ans;
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n+1, vector<int>(2*n+2, -1));
        return market(prices, 0, -2, prices.size());
    }
};
