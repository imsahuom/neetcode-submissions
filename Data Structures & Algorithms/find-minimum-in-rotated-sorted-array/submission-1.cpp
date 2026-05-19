class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m=0, n = nums.size();
        while(l < r){
            m = (l+r)/2;
            if (nums[m] < nums[r]) r = m;
            else if (nums[m] > nums[r]) l = m + 1;
        }
        return nums[l];
    }
};