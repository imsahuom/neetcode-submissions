class Solution {
public:
    vector<vector<string>> res;
    bool valid(string& s){
        int l = 0, r = s.size() - 1;
        while (l < r){
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void helper(string& s, int i, vector<string>& curr){
        if (i >= s.size()){
            res.push_back(curr); return;
        }
        string str = "";
        for(int j = i; j<s.size(); j++){
            str += s[j];
            if (valid(str)) {
                curr.push_back(str);
                helper(s, j+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(s, 0, curr);
        return res;
    }
};