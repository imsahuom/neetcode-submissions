class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();
        //normal brute force is just scan all the intervals for each query and update the ans at end
        vector<int> ans(q, 1e9);
        int i = -1;//this will become 0 on next index, and then give us index of que
        for(auto& que: queries){
            i++;
            for(auto& v: intervals){
                if (v[0] <= que && que <= v[1]) ans[i] = min(ans[i], v[1]-v[0]+1);
            }
        }
        for(int i=0; i<q; i++){
            if (ans[i] == 1e9) ans[i] = -1;
        }
        return ans;
    }
};