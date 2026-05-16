class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), l = 0, r = n2-1;
        vector<int> v1(26, 0);
        for (auto c: s1) v1[c - 'a']++;
        for (int i=0; i<=n2-n1; i++){
            vector<int> v2(26, 0);
            for (int j=i; j<i+n1; j++){
                v2[s2[j] - 'a']++;
            }
            if (v1 == v2) return true;
        }
        return false;
    }
};
