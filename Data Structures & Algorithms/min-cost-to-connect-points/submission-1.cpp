class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; ++i) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //so basically run dijsktra from first point, assuming all nodes are connected to all nodes
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (i==j) continue;
                edges.push_back({abs(points[j][0]-points[i][0]) + abs(points[i][1] - points[j][1]), {i, j}});
            }
        }
        DSU ds(n);
        sort(edges.begin(), edges.end());
        int ans = 0;

        for(auto& [w, a]: edges){
            int x = a.first, y = a.second;
            if (ds.unionSets(x, y)){
                ans += w;
            }
        }

        return ans;
    }
};













