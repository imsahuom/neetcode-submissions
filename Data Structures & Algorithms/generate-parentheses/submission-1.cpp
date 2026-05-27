class Solution {
public:
    vector<string> ans;
    void helper(int a, int b, int &total, string& curr){
        if (a == total && b == total){
            ans.push_back(curr);
            return;
        }
        if (a < total){
            curr.push_back('(');
            helper(a+1, b, total, curr);
            curr.pop_back();
        }
        if (a > b){
            curr.push_back(')');
            helper(a, b+1, total, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        helper(0, 0, n, curr);
        return ans;
    }
};