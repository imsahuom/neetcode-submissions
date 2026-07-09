class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0){
            int rem = n%26;
            n/=26;
            if (rem == 0){ rem = 26;n--;}
            ans += ('A' + rem - 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};