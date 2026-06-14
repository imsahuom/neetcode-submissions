class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        bool flag = false;
        int ns = newInterval[0], ne = newInterval[1];
        for(int i=0; i<n; i++){
            auto v = intervals[i];
            int st = v[0], en = v[1];
            if (st > ne || en < ns) res.push_back(v);//we're happy with that
            else{
                st = min(ns, st); en = max(en, ne);
                while(i < n){
                    if(intervals[i][0] <= en){
                        en = max(en, intervals[i][1]);
                        i++;
                    }else{
                        i--;
                        break;
                    }
                }
                flag = true;
                res.push_back({st, en});
            }
        }
        if (!flag){
            //we need to push newInterval and it's not overlapping with other
            res.clear();
            for(auto& v: intervals){
                if (v[0]> ne && !flag){
                    res.push_back(newInterval);
                    flag = true;
                }
                res.push_back(v);
            }
            if (!flag) res.push_back(newInterval);
        }
        return res;
    }
};