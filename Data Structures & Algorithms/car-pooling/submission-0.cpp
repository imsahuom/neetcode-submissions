class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1003, 0);
        int n = 0;
        for(auto& v: trips){
            diff[v[1]] += v[0];
            diff[v[2]] -= v[0];
            n = max(n, v[2]+2);
        }
        for(int i=1; i<n; i++) diff[i]+=diff[i-1];
        if (*max_element(diff.begin(), diff.end()) > capacity) return false;
        return true;
    }
};