class Solution {
public:
    bool isPalindrome(string s) {
        string tc = "";
        for (auto c: s){
            if (isalnum(c)) tc += tolower(c);
        }
        string s2 = tc; 
        reverse(tc.begin(), tc.end());
        // cout << s2 << endl;
        // cout << tc << endl;
        return (s2 == tc);
    }
};
