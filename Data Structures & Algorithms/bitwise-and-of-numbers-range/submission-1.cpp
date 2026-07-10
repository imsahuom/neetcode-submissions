class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        int i = left;
        while (i < right) {
            ++i;
            ans &= i;
            if (ans == 0) return 0;
        }
        return ans;
    }
};