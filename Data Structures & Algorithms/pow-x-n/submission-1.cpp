class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        double ans = x;
        if (n < 0) {ans = 1/x; n = -n; x = 1/x;}//now we'll find myPow(ans, n)
        double stock = 1;
        while (n > 1){
            if(n%2 == 0){
                ans = ans*ans;
                n /= 2;
            }else{
                stock *= ans;
                n--;
            }
        }
        ans *= stock;
        return ans;
    }
};