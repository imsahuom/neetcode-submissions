class Solution {
public:
    vector<vector<int>> res;
    void so(vector<int>& candidates, int target, int i, vector<int> & curr){
        if (target == 0){res.push_back(curr); return;}
        if (i >= candidates.size() || target < 0) return;
        curr.push_back(candidates[i]);
        so(candidates, target-candidates[i], i+1, curr);
        curr.pop_back();
        while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        so(candidates, target, i+1, curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        so(candidates, target, 0, curr);
        return res;
    }
};