class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> ans;
    void dfs(string& s, int i, int n, string& curr, string& ins){
        if (i >= n){
            // cout << ins << "+ " << curr << endl;
            if (mp.count(curr)){
                if (ins != "") ins += " ";
                ins += curr;
                ans.push_back(ins);
            }
            return;
        }
        if (mp.count(curr)){
            string oldCurr = curr;
            string oldIns = ins;
            if (ins != "") ins += " ";
            ins += curr;
            curr = "";
            dfs(s, i, n, curr, ins);
            curr = oldCurr;
            ins = oldIns;
        }
        curr.push_back(s[i]);
        dfs(s, i+1, n, curr, ins);
        curr.pop_back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& a: wordDict) mp[a]++;//this thing is present
        string curr = "", ins = "";
        dfs(s, 0, s.size(), curr, ins);
        return ans;
    }
};