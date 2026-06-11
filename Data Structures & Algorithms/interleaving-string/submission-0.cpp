class Solution {
public:
    vector<vector<vector<int>>> mp;
    bool help(string& s1, string& s2, string& s3, int i1, int i2, int i3){
        if (i3 >= s3.size() && i1 >= s1.size() && i2 >= s2.size()) return 1;
        else if (i1 >= s1.size() && i2 >= s2.size()) return 0;
        if (mp[i1][i2][i3] != -1) return mp[i1][i2][i3];
        int ans = 0;
        if (i1 >= s1.size()){
            if (s2[i2] == s3[i3]) ans += help(s1, s2, s3, i1, i2+1, i3+1);
        }else if (i2 >= s2.size()){
            if (s1[i1] == s3[i3]) ans += help(s1, s2, s3, i1+1, i2, i3+1);
        }else{
            if (s2[i2] == s3[i3]) ans += help(s1, s2, s3, i1, i2+1, i3+1);
            if (s1[i1] == s3[i3]) ans += help(s1, s2, s3, i1+1, i2, i3+1);
        }
        return mp[i1][i2][i3] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        mp.assign(s1.size()+1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size()+1, -1)));
        return help(s1, s2, s3, 0, 0, 0);
    }
};