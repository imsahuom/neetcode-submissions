class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n+1, 0);
        rank.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int up(int i){
        if (parent[i] == i) return i;
        return parent[i] = up(parent[i]);
    }

    void unite(int u, int v){
        int pu = up(u);
        int pv = up(v);
        if (pu == pv) return;
        if (rank[(pu)] > rank[(pv)]){
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }else if (rank[(pv)] > rank[(pu)]){
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }else{
            parent[pv] = pu;
            rank[pu]+=rank[pv];
        }
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = n;
        auto ds = DSU(n);
        for(auto& e: edges){
            int u = e[0], v = e[1];
            if(ds.up(u) != ds.up(v)) ans--;
            ds.unite(u, v);
        }
        return ans;
    }
};
