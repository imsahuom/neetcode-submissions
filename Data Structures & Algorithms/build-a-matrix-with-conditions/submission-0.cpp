class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> ro, co;//row order and col order
        vector<int> ind(k+1, 0);//stores indegree
        vector<vector<int>> adj(k+1);
        for(auto& v: rowConditions){
            ind[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }
        queue<int> q;
        for(int i=1; i<=k; i++){
            if (ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto n = q.front(); q.pop();
            ro.push_back(n);
            for(auto& x: adj[n]){
                ind[x]--;
                if (ind[x] == 0) q.push(x);
            }
        }
        if (ro.size() != k) return {};
        vector<int> ind1(k+1, 0);
        vector<vector<int>> adj1(k+1);
        for(auto& v: colConditions){
            ind1[v[1]]++;
            adj1[v[0]].push_back(v[1]);
        }
        queue<int> q1;
        for(int i=1; i<=k; i++){
            if (ind1[i] == 0) q1.push(i);
        }
        while(!q1.empty()){
            auto n = q1.front(); q1.pop();
            co.push_back(n);
            for(auto& x: adj1[n]){
                ind1[x]--;
                if (ind1[x] == 0) q1.push(x);
            }
        }
        if (co.size() != k) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            ind[ro[i]] = i;//now we know posn of ro[i] 
            ind1[co[i]] = i;
        }
        for(int i=1; i<=k; i++){
            ans[ind[i]][ind1[i]] = i;
        }
        return ans;
    }
};