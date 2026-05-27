class Solution {
public:
    vector<string> res;
    void helper(string& digits, int i, vector<vector<char>>& v, string& curr){
        if (i >= digits.size()){
            res.push_back(curr); return;
        }
        int k = digits[i] - '0';
        for(auto x: v[k]){
            curr.push_back(x);
            helper(digits, i+1, v, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        vector<vector<char>> mp={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        string curr = "";
        helper(digits, 0, mp, curr);
        return res;
    }
};