class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(auto& a: nums){
            if(a>0) s.insert(a);
        }
        int ans = 1;
        for(auto& x: s){
            if (x == ans) ans++;
            else return ans;
        }
        return ans;
    }
};