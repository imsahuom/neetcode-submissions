class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> dead;
        for(auto& c: deadends) dead[c]++;
        if (dead.count("0000") && target != "0000") return -1;
        queue<string> q;
        unordered_map<string, int> mp;
        mp["0000"] = 1;
        q.push("0000");
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto s = q.front(); q.pop();
                if (s == target) return ans;
                string next = s;
                for(int i=0; i<4; i++){
                    auto temp = next[i];
                    if (next[i] == '9') next[i] = '0';
                    else next[i]++;
                    if (!dead.count(next) && !mp.count(next)) {q.push(next); mp[next]++;}
                    next[i] = temp;
                    if (next[i] == '0') next[i] = '9';
                    else next[i]--;
                    if (!dead.count(next) && !mp.count(next)) {q.push(next); mp[next]++;}
                    next[i] = temp;
                }
            }
            ans++;
        }
        return -1;
    }
};