class Solution {
public:
    int idx(char c){
        return ('a' <= c && c <= 'z') ? c-'a' : c-'A'+26;
    }
    string minWindow(string s, string t) { 
        int n = s.size(), m = t.size();
        vector<int> freq(52, 0), freqt(52, 0), zero(52, 0);
        for(auto c: s) freq[idx(c)]++;
        for(auto c: t) freqt[idx(c)]++;

        for(int i=0; i<52; i++){
            if(freq[i] < freqt[i]) return "";
        }
        string ans = s;
        for(int i=0; i<=n-m; i++){
            vector<int> check = freqt;
            string curr = "";
            int j = 0;

            while(check != zero && i+j < n && j < ans.size()){
                if(check[idx(s[i+j])] > 0)
                    check[idx(s[i+j])]--;
                curr += s[i+j];
                j++;
            }
            if(check == zero && curr.size() < ans.size())
                ans = curr;
        }
        return ans;
    }
};