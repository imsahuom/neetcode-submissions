class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int> prices;
        prices.push_back(p[0]);
        for(int i=1; i<p.size(); i++){
            if (p[i] == p[i-1]) continue;
            prices.push_back(p[i]);//I want only unique elements, otherwise i may buy much
        }
        if (prices.size() <= 1) return 0;
        int n = prices.size();
        vector<int> peaks(n, 0);
        //peak[i] = 1 - peak 0-trash -1 valley
        if (prices[1] > prices[0]) peaks[0] = -1;
        if (prices[n-1] > prices[n-2]) peaks[n-1] = 1;
        for(int i=1; i<n-1; i++){
            if (prices[i] > prices[i-1] && prices[i] > prices[i+1]) peaks[i] = 1;
            else if (prices[i] < prices[i-1] && prices[i] < prices[i+1]) peaks[i] = -1;
        } 
        int ans = 0;
        for(int i=0; i<n; i++){
            if (peaks[i] == 1) ans += prices[i];
            else if (peaks[i] == -1) ans -= prices[i];
        }
        for(auto& p: peaks) cout << p << " ";
        return ans;
    }
};