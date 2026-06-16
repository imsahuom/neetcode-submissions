class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), k = n;
        for(int i=0; i<n; i++){
            if (nums[i] == val) {nums[i] = 51;k--;}
        }
        sort(nums.begin(), nums.end());
        return k;
    }
};