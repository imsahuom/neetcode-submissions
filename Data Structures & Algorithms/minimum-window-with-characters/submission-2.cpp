class Solution {
public:
    string minWindow(string s, string t) { 
        int n = s.size(), m = t.size(), cnt = 0;
        unordered_map<char, int> mp;
        for (auto c: t) mp[c]++;
        int l = 0, r = 0, st = 0, len = 2e9;
        while (r<n){
            if (mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while (cnt == m){
                if(r-l+1 < len){
                    len = r-l+1;
                    st = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return len == 2e9 ? "" : s.substr(st, len);
    }
};