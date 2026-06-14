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
        priority_queue<int, vector<int>, greater<int>> rooms;
        int ans = 0;
        for(auto i: intervals){
            bool flag = true;
            while(!rooms.empty()){
                if(rooms.top() > i.start) break;
                else{
                    rooms.pop();
                    rooms.push(i.end);
                    flag = false;
                    break;
                }
            }
            if(flag){ rooms.push(i.end); ans++;}//created a new room
        }        
        return ans;
    }
};
