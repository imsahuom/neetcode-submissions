class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (auto &s: strs){
            ans += to_string(s.size()) + '#' + s;
        }
        return ans;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()){
            int j = i; string nos = "";
            while (s[j] != '#'){
                nos += s[j];
                j++;
            }
            int n = stoi(nos);
            ans.push_back(s.substr(j + 1, n));
            i += n + nos.size() + 1;
        }
        return ans;
    }
};
