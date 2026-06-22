class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r - l)/2;
            if (nums[m] == target) return true;
            else if (nums[m] > nums[l]){
                //this half is sorted
                if (target <= nums[m] && nums[l] <= target) r = m;
                else l = m+1;
            }else if (nums[l] > nums[m]){
                //this half is not sorted, check ans in right half
                if (target <= nums[r] && nums[m] <= target) l = m;
                else r = m - 1;
            }else l++;
        }
        return false;
    }
};