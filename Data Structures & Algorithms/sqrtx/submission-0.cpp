class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long v = (long long) mid* mid;
            if (x == v) return mid;
            if (x > v) l = mid+1;
            else r = mid - 1; 
        }
        return l-1;
    }
};