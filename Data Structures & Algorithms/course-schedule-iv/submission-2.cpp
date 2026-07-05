class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n); vector<int> good(n, 0);
        vector<unordered_set<int>> pre(n);
        for(auto& x: prerequisites){
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            good[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if (good[i] == 0){ q.push(i);
            good[i] = -1;//means visited node
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto& v: adj[u]){
                pre[v].insert(u);
                for(auto& x: pre[u]) pre[v].insert(x);
                good[v]--;
                if (good[v] == 0){
                    good[v] = -1;
                    q.push(v);
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     cout << i << "->";
        //     for(auto& x: pre[i]) cout << x << " "; cout << endl;
        // }
        int m = queries.size();
        vector<bool> ans(m, false);
        for(int i=0; i<m; i++){
            int u = queries[i][0], v = queries[i][1];
            if (pre[v].count(u)) ans[i] = true;
        }
        return ans;
    }
};