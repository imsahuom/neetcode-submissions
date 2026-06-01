class DSU {
    vector<int> parent;
    vector<int> siz;
public:
    DSU(int n) {
        parent.resize(n + 1);
        siz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]); 
    }

    // Now returns false if a cycle is detected!
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // Already in the same set
        
        if (siz[pv] > siz[pu]) swap(pu, pv);
        parent[pv] = pu;
        siz[pu] += siz[pv];
        return true; 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Fast I/O (Bypasses C/C++ stream synchronization overhead)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = edges.size();
        DSU ds(n);
        
        for(auto& e : edges) {
            // If unite returns false, we found our cycle! Return immediately.
            if (!ds.unite(e[0], e[1])) {
                return e;
            }
        }
        
        return {}; // Fallback, though the problem guarantees an answer
    }
};