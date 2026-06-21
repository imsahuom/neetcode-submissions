class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        stack<string> str;
        int i =0;
        string curr = "";
        while(i<n){
            if(s[i] != ']') str.push(curr+s[i]);
            else{
                string add = "";
                while(!str.empty() && str.top() != "["){
                    add = str.top() + add;
                    str.pop();
                }
                str.pop();
                string cnt = "";
                while(!str.empty() && isdigit(str.top()[0])){
                    cnt = str.top() + cnt;
                    str.pop();
                }
                int k = stoi(cnt);
                string res = "";
                while(k--) res += add;
                str.push(res);
            }
            i++;
        }
        string final = "";
        while(!str.empty()){
            final = str.top() + final;
            str.pop();
        }
        return final;
    }
};