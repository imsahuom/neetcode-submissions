class Solution {
public:
    int n, k;
    bool dfs(vector<int>& v, int i, int a, int b, int c, int d){
        if (i >= n){
            if (a == k && b == k && c == k && d == k) return true;
            return false;
        }
        if(a + v[i] <= k) { if(dfs(v, i+1, a + v[i], b, c, d)) return true;}
        if(b + v[i] <= k) { if(dfs(v, i+1, a, b + v[i], c, d)) return true;}
        if(c + v[i] <= k) { if(dfs(v, i+1, a, b, c + v[i], d)) return true;}
        if(d + v[i] <= k) { if(dfs(v, i+1, a, b, c, d + v[i])) return true;}
        return false;
    }
    bool makesquare(vector<int>& ma) {
        n = ma.size();int total = 0;
        for(auto& a: ma) total+=a;
        if (total%4 != 0) return false;
        k = total/4;
        //now we need 4 sets of total k each
        sort(ma.rbegin(), ma.rend());
        return dfs(ma, 0, 0, 0, 0, 0);
    }
};