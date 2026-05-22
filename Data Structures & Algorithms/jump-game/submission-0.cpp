class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0, i = 0;
        while (i<n && i <= reach){
            reach = max(reach, nums[i] + i);
            i++;
        }
        reach++;
        if (reach < n) return false;
        return true;
    }
};
