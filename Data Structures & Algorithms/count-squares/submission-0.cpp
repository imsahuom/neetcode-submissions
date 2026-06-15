class CountSquares {
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> v;
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        if (!mp.count({x, y})) v.push_back({x, y});
        mp[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for(auto& [a, b]: v){
            if (a == x && b == y) continue;//ensures if a=x then b!=y further
            if (a != x && b != y){
                if (mp.count({a, y}) && mp.count({x, b}) && abs(a-x) == abs(b-y)){
                    ans += mp[{a, y}]*mp[{x, b}]*mp[{a, b}]; 
                }
            }
        }
        return ans;
    }
};











