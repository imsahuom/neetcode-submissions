class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();
        for(int i=1; i<n; i++){
            int cst = intervals[i][0], cen = intervals[i][1];
            if (cst > end){
                res.push_back({st, end});
                st = cst;
                end = cen;
            }else{
                //we can merge the intervals here, so let's do that
                st = min(st, cst);
                end = max(cen, end);
                // cout << st << " " << cst << " with " << cen << " " << end << endl;
            }
        }
        res.push_back({st, end});
        return res;
    }
};
