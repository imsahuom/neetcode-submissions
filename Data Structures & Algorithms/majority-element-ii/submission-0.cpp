class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int f = 0, c = nums[0];
        for(int i=0; i<n; i++){
            if (c != nums[i]){
                if (i - f > ((n)/3)){ans.push_back(c);}
                f = i;
                c = nums[i];
            }
        }
        if (n - f > ((n)/3)){ans.push_back(c);}
        return ans;
    }
};