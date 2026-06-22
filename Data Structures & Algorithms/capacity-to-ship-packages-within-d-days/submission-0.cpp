class Solution {
public:
    bool can(vector<int>& w, int k, int c){
        int n = w.size();
        int i=0; 
        while(i<n){
            int sum = 0;
            if (w[i] > c) return false;
            while(i<n && sum + w[i] <= c){
                sum += w[i];
                i++;
            }
            k--;
            if (k<0) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 1e9, l = 0;
        int ans = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if (can(weights, days, mid)){
                ans = min(ans, mid);
                r = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
};