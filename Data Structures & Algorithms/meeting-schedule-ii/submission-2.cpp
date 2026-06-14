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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if (a.start!= b.start) return a.start < b.start;
            return a.end < b.end;
        });
        vector<int> rooms;
        for(auto i: intervals){
            if (rooms.size() == 0) rooms.push_back(i.end);
            else{
                int maxi = -1;
                for(int j=0; j<rooms.size(); j++){
                    //if valid maxi is max rooms[i];
                    if (i.start >= rooms[j]){
                        if(maxi == -1 || rooms[maxi] > rooms[j]) maxi = j;
                    }
                }
                if (maxi == -1) rooms.push_back(i.end);
                else rooms[maxi] = i.end;
            }
        }        
        return rooms.size();
    }
};
