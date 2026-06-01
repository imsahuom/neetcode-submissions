class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        int n = wordlist.size(), ans = 1;
        unordered_map<string, int> mp;
        for(auto& s: wordlist){
            mp[s]++;
        }
        vector<char> letters(26);
        int l = beginword.size();
        for(int i=0; i<26; i++) letters[i] = 'a' + i;
        queue<string> q;
        q.push(beginword);
        while(!q.empty()){
            int k = q.size();
            ans++;
            while(k--){
                string curr = q.front(); q.pop();
                for(int i=0; i<l; i++){
                    auto c = curr[i];
                    for(int j=0; j<26; j++){
                        curr[i] = letters[j];
                        if (mp.count(curr)){
                            if (curr == endword) return ans;
                            q.push(curr);
                            mp.erase(curr);
                        }
                        curr[i] = c;
                    }
                }
            }
        }
        return 0;
    }
};