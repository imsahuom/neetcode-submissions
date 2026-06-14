class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        auto end = intervals[0][1];
        int n = intervals.size();
        int ans = 0;
        //so we'll track if any interval is clashing we'll remove further one
        for(int i=1; i<n; i++){
            int cst = intervals[i][0], cen = intervals[i][1];
            if (cst >= end){
                //we can have another interval
                end = cen;
            }else{
                //we got a clashing shit
                ans++;//we'll keep the previous one, like if we've 1, 5 and 2, 4 we'll keep 2, 4
                end = min(end, cen);
            }
        }
        return ans;
    }
};
