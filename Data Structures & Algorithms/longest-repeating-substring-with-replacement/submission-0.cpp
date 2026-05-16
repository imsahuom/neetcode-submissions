class Solution {
public:
    int characterReplacement(string str, int k) {
        vector<char> c;
        for (int i=0; i<26; i++) c.push_back('A' + i);
        int final = 0, n = str.size();
        for(auto x: c){
            int l = 0, r = 0;
            int ans = 0;
            int count = 0;
            while (r < n){
                if (str[r] != x){
                    count++;
                }
                while (count > k) {
                    if (str[l] != x) count--;
                    l++;
                }
                ans = max(ans, r-l+1);
                r++;
            }
            final = max(final, ans);
        }
        return final;
    }
};