class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            if (s[i] - 'a' >=0 && s[i] - 'a' <= 26){
                ans += s[i];
            }else if (s[i] - '0' <= 9 && s[i]-'0' >= 0){
                string str = "";
                int cnt = 0;
                while(i<n && s[i] - '0' <= 9 && s[i] - '0' >= 0){
                    str += s[i];
                    i++;
                }
                cnt = stoi(str);
                int open = 1;
                if (s[i] == '[') i++;//now the game begins
                int st = i;
                while (true){
                    if (s[i] == ']' && open == 1) break;
                    if (s[i] == '[')open++;
                    if (s[i] == ']')open--;
                    i++;
                }
                cout << cnt << " " << s.substr(st, i-st+1) <<endl;
                string add = decodeString(s.substr(st, i-st+1));
                while(cnt--) ans += add;
            }
        }
        return ans;
    }
};