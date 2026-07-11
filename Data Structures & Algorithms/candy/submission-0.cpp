class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> childs;
        for(int i=0; i<n; i++) childs.push({rate[i], i});
        vector<int> give(n, 0);
        int ans = 0;
        while(!childs.empty()){
            auto [c, i] = childs.top(); childs.pop();
            int left = 0, right = 0;
            if (i-1 >= 0 && rate[i] > rate[i-1]) left = give[i-1];
            if (i+1 < n && rate[i] > rate[i+1]) right = give[i+1];
            give[i] = max(1 + left, 1 + right);
            ans += give[i];
        }
        for(auto& x: give) cout << x << " ";
        return ans;
    }
};