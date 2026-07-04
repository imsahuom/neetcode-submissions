class Solution {
public:
    bool check(string& a, string& b, unordered_map<char, int>& mp){
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            if (a[i] == b[j]){i++; j++; continue;}
            if (mp[a[i]] < mp[b[j]]){
                i++; j++;
                return false;
            }else return true;
        }
        if (n > m) return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;   
        for(int i=1; i<27; i++){
            mp[order[i]] = i;
        }
        int n = words.size();
        for(int i=0; i<n-1; i++){
            auto a = words[i]; auto b = words[i+1];
            if (check(a, b, mp)) return false;
        }
        return true;
    }
};