/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> meets;
        for(auto& i: intervals){
            meets.push_back({i.start, i.end});
        }
        sort(meets.begin(), meets.end());
        int n = meets.size();
        if (n == 0) return true;
        int st = meets[0].first, end = meets[0].second;
        for(int i=1; i<n; i++){
            // cout << end << " " << meets[i].first << endl;
            if (meets[i].first < end) return false;
            else{
                st = meets[i].first;
                end = meets[i].second;
            }
        }
        return true;
    }
};
