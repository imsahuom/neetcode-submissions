class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //so basically run dijsktra from first point, assuming all nodes are connected to all nodes
        int n = points.size();
        vector<int> distance(n, INT_MAX), visited(n, 0);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int ans = 0, total = 0;
        pq.push({0, 0});//distance, index
        while(!pq.empty() && total < n){
            auto [d, i] = pq.top(); pq.pop();
            if (visited[i]) continue;

            visited[i] = 1;
            ans+=d;
            total++;
            for(int j=0; j<n; j++){
                if(i==j || visited[j]) continue;
                int dt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                if(dt < distance[j]){
                    distance[j] = dt;
                    pq.push({dt, j});
                }
            }
        }
        return ans;
    }
};