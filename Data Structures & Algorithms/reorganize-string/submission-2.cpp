class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cntss(26, 0);
        int n = s.size();
        for(auto& c: s) cntss[c-'a']++;
        vector<pair<int, char>> cnt;
        for(int i=0; i<26; i++){
            cnt.push_back({cntss[i],'a' + i});
        }
        sort(cnt.rbegin(), cnt.rend());
        if (cnt[0].first > (n+1)/2) return "";
        int i = 0, j = 0;
        vector<char> ans(n, 'a');
        while (i < n){
            while(cnt[j].first > 0){
                ans[i] = cnt[j].second;
                cnt[j].first--;
                i+=2;
                if (i >= n) break;
            }
            if (i>=n)break;
            j++;
        }
        i = 1;
        // cout << j << " " << cnt[j].second;
        while(i < n){
            while(cnt[j].first > 0){
                ans[i] = cnt[j].second;
                cnt[j].first--;
                i+=2;
                if (i >= n) break;
            }
            j++;
        }
        string res = "";
        for(auto& x: ans) res += x;
        return res;
    }
};