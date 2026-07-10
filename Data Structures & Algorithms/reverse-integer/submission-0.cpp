class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        if (str[0] == '-') ::reverse(str.begin()+1, str.end());
        else ::reverse(str.begin(), str.end());
        try {
            return stoi(str);
        }
        catch (const std::out_of_range&) {
            return 0;
        }
    }
};