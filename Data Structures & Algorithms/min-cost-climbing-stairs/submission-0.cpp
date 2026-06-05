class Solution {
public:
    vector<int> totals;

    int costtohere(vector<int>& cost, int posn){
        if (posn < 0) return 0;
        int ans = 0;
        if (posn < cost.size()) ans = cost[posn];
        if (totals[posn] != -1) return totals[posn];
        return totals[posn] = ans + min(costtohere(cost, posn-1), costtohere(cost, posn-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        totals.resize(n+2, -1);
        return costtohere(cost, n);
    }
};
