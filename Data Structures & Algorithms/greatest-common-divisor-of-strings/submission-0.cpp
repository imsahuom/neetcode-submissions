class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a1 = 0, a2 = 0;
        string a = str1 + str2, b = str2 + str1;
        if (a != b) return "";
        for(auto& c: str1) a1 += (c - 'A' + 1);
        for(auto& c: str2) a2 += (c - 'A' + 1);
        int g = gcd(a1, a2);
        string ans = "";
        if (g == 1){
            for(auto& c: str1){
                if (c != 'A') return "";
            }
            for(auto& c: str2){
                if (c != 'A') return "";
            }
        }
        int i = 0, sum = 0;
        while(sum < g ){
            ans += str1[i];
            sum += (str1[i] - 'A' + 1);
            i++;
        }
        return ans;
    }
};