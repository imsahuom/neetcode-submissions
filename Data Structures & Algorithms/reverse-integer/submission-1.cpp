class Solution {
public:
    int mini = INT_MIN, maxi = INT_MAX;
    int reverse(int x) {
        int ans = 0;
        if (x == mini) return 0;
        bool neg = false;
        if (x < 0) {x = -x; neg = true;}
        while (x > 0){
            if (ans > maxi/10) return 0;
            if (ans == maxi/10 && x%10 > 8) return 0;
            ans = ans*10 + x%10;
            x/=10;
        }
        if (neg) return -ans;
        return ans;
    }
};