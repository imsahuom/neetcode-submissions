class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while (i <= j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int len = 1;
        int idx = 0;
        for(int i = n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                //check whether str[i:j] is palindrome or not
                if (s[i] != s[j]) continue;
                if ((j-i < 2) || (i+1 <= j-1 && dp[i+1][j-1] == 1)){
                    //so i,j is valid, 
                    dp[i][j] = 1;
                    if (j-i+1 > len){
                        len = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
};
