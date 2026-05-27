class Solution {
public:
    vector<string> ans;
    void helper(int a, int b, stack<char>& s, string curr){
        // cout << curr << " " << a << " " << b << " " << endl;
        if (a == 0 && b == 0){
            ans.push_back(curr);
            return;
        }
        if (s.empty()){
            s.push('(');
            string temp = curr+'(';
            helper(a - 1, b, s, temp);
            s.pop();
        }else{
           //Choice 1 - '('
            if (a > 0){
                s.push('(');
                string temp = curr+'(';
                helper(a - 1, b, s, temp);
                s.pop();
            }
            //Choice 2, ')' then pop the top element and add '()' to the string
            if (a >= 0 && b > 0){
                s.pop();
                string temp = curr + ')';
                helper(a, b-1, s, temp);
                s.push('(');
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        stack<char> s;
        string curr = "";
        helper(n, n, s, curr);
        return ans;
    }
};