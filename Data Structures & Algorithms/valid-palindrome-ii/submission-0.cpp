class Solution {
public:
    bool validPalindrome(string s) {
        bool flag = true;
        int l = 0, r = s.size()-1;
        while(l <= r){
            if (s[l] == s[r]){l++; r--;}
            else if (flag){
                flag = false;
                int l1 = l, r1 = r-1;
                bool path1 = true, path2 = true;
                while (l1 <= r1){
                    if (s[l1] != s[r1]){path1 = false; break;}
                    l1++;
                    r1--;
                }
                l++;
                while(l <= r){
                    if (s[l] != s[r]){path2 = false; break;}
                    l++; r--;
                }
                return (path1 || path2);
            }
        }
        return true;
    }
};