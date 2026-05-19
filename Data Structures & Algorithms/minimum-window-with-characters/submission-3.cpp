class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for(char c : t) freq[c]++;
        int l = 0, cnt = 0, st = 0, len = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1 < len){
                    len = r-l+1;
                    st = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(st, len);
    }
};