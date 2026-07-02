class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a>0) pq.push({a, 'a'}); 
        if (b>0) pq.push({b, 'b'}); 
        if (c>0) pq.push({c, 'c'});
        string ans = "";
        while(!pq.empty()){
            auto [x, cc] = pq.top(); pq.pop();
            if (x <= 1){ans += cc; continue;}
            else {ans +=cc; ans+=cc; x-=2;}
            if (pq.empty()) break;
            auto [y, d] = pq.top(); pq.pop();
            if (x > y || y <= 1){ans += d; y--;}
            else {ans += d; ans+=d; y-=2;}
            if (y>0) pq.push({y, d});
            if (x>0) pq.push({x, cc});
        }
        return ans;
    }
};