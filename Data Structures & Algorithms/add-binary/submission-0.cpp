class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while( i <= n || j <= m){
            int sum = 0;
            if (i < n) sum += (a[i] == '1') ? 1: 0;
            if (j < m) sum += (b[i] == '1') ? 1: 0;
            sum += carry;
            carry = sum/2;
            sum = sum%2;
            ans += (sum == 1) ? '1' : '0';
            i++; j++;
        }
        while(ans.size() >= 2 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};