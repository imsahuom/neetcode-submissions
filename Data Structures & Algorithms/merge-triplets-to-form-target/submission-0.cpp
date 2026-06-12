class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool fa = false, fb = false, fc = false;
        int x = target[0], y = target[1], z = target[2];
        for(auto& v: triplets){
            int a = v[0], b = v[1], c = v[2];
            if (a == x && b <= y && c <= z){fa = true;}
            if (a <= x && b == y && c <= z){fb = true;}
            if (a <= x && b <= y && c == z){fc = true;}
        }
        return (fa && fb && fc);
    }
};
