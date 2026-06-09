class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& v: flights){
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int> minStops(n, 1e9); 
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src, 0}); 

        while(!q.empty()){
            auto v = q.top(); q.pop();
            int c = v[0], no = v[1], stops = v[2];
            if (no == dst) return c; 

            if (stops >= minStops[no]) continue;
            minStops[no] = stops;
            if (stops > k) continue;

            for(auto& [neigh, cost]: adj[no]){
                q.push({c + cost, neigh, stops + 1});
            }
        }
        return -1;
    }
};