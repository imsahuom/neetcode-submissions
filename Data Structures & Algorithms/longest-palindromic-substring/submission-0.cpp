class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        string res = "";
        res += s[0];
        for(int i=1; i<n-1; i++){
            int l = i, r = i;
            while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]){
                l--;
                r++;
            }
            int len = r - l + 1;
            if (ans < len){
                cout << ans << " " << len << endl;
                res = s.substr(l, len);
                ans = len;
            }
        }
        for(int i=0; i<n; i++){
            int l = i+1, r = i;
            while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]){
                l--;
                r++;
            }
            int len = r - l + 1;
            if (ans < len){
                cout << ans << " " << len << endl;
                res = s.substr(l, len);
                ans = len;
            }
        }
        return res;
    }
};
