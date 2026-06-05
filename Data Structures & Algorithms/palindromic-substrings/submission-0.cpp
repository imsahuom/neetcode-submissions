class Solution {

public:

    int countSubstrings(string s) {

        int n = s.size();

        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=n-1; i>=0; i--){

            for(int j=i; j<n; j++){

                if (s[i] != s[j]) continue;

                if ( (j-i < 2) || (i+1 < n && j-1 >=0 && dp[i+1][j-1] == 1)){

                    dp[i][j] = 1;

                    ans++;

                }

            }

        }

        return ans;

    }

};


// so basically leetcode goons over Palindrome