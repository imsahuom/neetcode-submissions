class DSU{
    vector<int> parent;
    vector<int> siz;
    public:
    DSU(int n){
        parent.resize(n+1);
        siz.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find(int u){
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v){
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (siz[pv] > siz[pu]) swap(pu, pv);
        parent[pv] = pu;
        siz[pu] += siz[pv];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU ds(n);
        for(auto& e: edges){
            int u = e[0], v = e[1];
            if (ds.find(u) == ds.find(v)) ans = e;
            ds.unite(u, v);
        }
        return ans;
    }
};
