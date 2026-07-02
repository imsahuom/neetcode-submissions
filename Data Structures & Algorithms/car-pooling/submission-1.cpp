class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> v;
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });
        int d = 0, i = 0, n = trips.size();
        while(i < n){
            d = trips[i][1];
            if (v.empty()){
                if (capacity >= trips[i][0]){
                    capacity-= trips[i][0];
                    v.push({trips[i][2], trips[i][0]});//(end_time, passengers)
                    i++;
                }else return false;
            }else{
                while(!v.empty() && v.top().first <= d){
                    //we can move these cars out easily :)
                    capacity += v.top().second;
                    v.pop();
                }
                //now we can't move any more cars out, check that space is avail...
                if (capacity >= trips[i][0]){
                    capacity-= trips[i][0];
                    v.push({trips[i][2], trips[i][0]});
                    i++;
                }else return false;
            }
        }
        return true;
    }
};