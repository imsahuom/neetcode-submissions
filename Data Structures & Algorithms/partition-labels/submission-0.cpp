class Solution {
public:
    vector<int> partitionLabels(string s) {
        //for each letter take position as l_most & r_most, 
        //then for the first of l_most-r_most iterate and keep update of l_most & r_most
        //after that jump to r_most 
        unordered_map<int, pair<int, int>> mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            if (mp.count(s[i])){
                auto [l, r] = mp[s[i]];
                mp[s[i]] = {min(l, i), max(r, i)};
            }else{
                mp[s[i]] = {i, i};
            }
        }
        int i = 0;
        vector<int> ans;
        while(i < n){
            auto [l, r] = mp[s[i]];
            while (i < n && i < r){
                l = min(mp[s[i]].first, l);
                r = max(mp[s[i]].second, r);
                i++;
            }
            ans.push_back(r-l+1);
            i++;
            //here we reached to a new group
        }
        return ans;
    }
};
