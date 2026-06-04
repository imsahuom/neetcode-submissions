class Solution {
public:
    vector<string> ans;
    int n;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

    void dfs(string start){
        while(!adj[start].empty()){
            auto curr = adj[start].top();
            adj[start].pop();

            dfs(curr);
        }

        ans.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
       for(auto& v: tickets){
        adj[v[0]].push(v[1]);
       }
       dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
