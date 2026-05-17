class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (auto c: str){
            if (c == '(' || c == '{' || c == '[') s.push(c);
            else{
                if (s.empty()) return false;
                auto m = s.top();
                if ((c == '}' && m != '{') || (c == ']' && m != '[' )||( c == ')' && m != '(' )){
                    return false;
                }else s.pop();
            }
        }
        if (!s.empty()) return false;
        return true;
    }
};
