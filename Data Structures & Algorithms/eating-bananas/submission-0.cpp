class Solution {
public:
    long long time(vector<int>& piles,int k){
        long long ans = 0;
        for(auto p: piles) ans += (p+k-1)/k;
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, ans = 1e9, m = 0;
        while (l<=r){
            m  = l +  (r - l)/2;
            if (time(piles, m) <= h){ans = min(ans, m); r = m-1;}
            else l = m+1;
        }
        return ans;
    }
};