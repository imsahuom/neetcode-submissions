class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        int l1 = 0, l2 = 0;
        //first add m letters from both
        string ans = "";
        while (l1 < n && l2 < m){
            ans += word1[l1];
            ans += word2[l2];
            l1++; l2++;
        }
        while(l1 < n){ans += word1[l1]; l1++;}
        while(l2 < m){ans += word2[l2]; l2++;}
        return ans;
    }
};