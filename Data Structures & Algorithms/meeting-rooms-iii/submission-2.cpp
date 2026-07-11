class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        int m = meet.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> start, end;
        vector<int> rooms(n, 0);
        for(auto& v: meet) start.push({v[0], v[1]});
        priority_queue<int, vector<int>, greater<int>> free;
        for(int i=0; i<n; i++) free.push(i);
        while(!start.empty()){
            auto [s, e] = start.top(); start.pop();
            while(!end.empty() && end.top().first <= s){
                free.push(end.top().second);
                end.pop();
            }
            if (!free.empty()){
                int i = free.top(); free.pop();
                end.push({e, i}); rooms[i]++;
            }else{
                auto [l, il] = end.top(); end.pop();
                rooms[il]++;
                end.push({e + (l - s), il});
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout << rooms[i] << " ";
            if (rooms[i] > rooms[ans]) ans = i;
        }
        return ans;
    }
};