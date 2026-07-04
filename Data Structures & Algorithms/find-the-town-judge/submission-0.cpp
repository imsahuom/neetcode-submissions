class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t1(n+1, 1), t2(n+1, 0);
        for(auto& v: trust){
            t1[v[0]] = 0;
            t2[v[1]]++;
        }
        for(int i=1; i<=n; i++){
            if (t2[i] == n-1 && t1[i] == 1) return i;
        }
        return -1;
    }
};