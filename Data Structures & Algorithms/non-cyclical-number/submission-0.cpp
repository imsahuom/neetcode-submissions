class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> st;
        while(n != 1){
            int k = n;
            if (st.count(k)) return false;
            st[n]++;
            n = 0;
            while(k > 0){
                n += (k%10)*(k%10);
                k /= 10;
            }
        }
        return true;
    }
};