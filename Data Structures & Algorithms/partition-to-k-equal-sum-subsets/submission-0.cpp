class Solution {
public:
    int n, m, k;
    bool dfs(vector<int>& v, int i, vector<int>& s){
        if (i >= n){
            sort(s.begin(), s.end());
            return (s[0] == k && s[m-1] == k);
        }
        for(int j=0; j<m; j++){
            while(j+1<m && s[j] == s[j+1]) j++;
            if (s[j] + v[i] > k) continue;
            s[j] += v[i];
            if (dfs(v, i+1, s)) return true;
            s[j] -= v[i];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& ma, int v) {
        n = ma.size(); m = v;int total = 0;
        for(auto& a: ma) total+=a;
        if (total%m != 0) return false;
        k = total/m;
        //now we need m sets of total k each
        sort(ma.rbegin(), ma.rend());
        vector<int> sets(m, 0);//target is to make all the elements of this = k
        return dfs(ma, 0, sets);
    }
}; 