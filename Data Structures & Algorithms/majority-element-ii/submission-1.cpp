class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for(auto& a: nums){
            if (c1 == a) cnt1++;
            else if (c2 == a) cnt2++;
            else if (cnt1 == 0){
                c1 = a;
                cnt1++;
            }else if (cnt2 == 0){
                c2 = a;
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        if (cnt1 != 0){
            cnt1 = 0;
            for(auto& a: nums){
                if (a == c1) cnt1++;
            }
            if (cnt1 > n/3) ans.push_back(c1);
        }
        if (cnt2 != 0){
            cnt2 = 0;
            for(auto & a: nums){
                if (a == c2) cnt2++;
            }
            if (cnt2 > n/3) ans.push_back(c2);
        }
        return ans;
    }
};