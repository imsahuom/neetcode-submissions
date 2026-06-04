class Solution {
public:
    vector<string> ans;
    int n;

    bool dfs(unordered_map<string, vector<string>>& mp, string start){
        if (ans.size() > n) return true;
        for(auto& a: mp[start]){
            if (a == "#") continue;
            string s = a;
            a = "#";//mark this ticket visited
            ans.push_back(s);
            if(!dfs(mp, s)){
                ans.pop_back();
                a = s;//backtrack
            }else return true;
            //okay explore here, i.e. go to this place
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        n = tickets.size();
        for(auto& v: tickets){
            mp[v[0]].push_back(v[1]);
        }
        for(auto& [a, v]: mp) sort(v.begin(), v.end());
        ans.push_back("JFK");
        dfs(mp, "JFK");

        return ans;
    }
};
