class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l1 = 0, idx = 0;
        int curr = nums[0];
        int k = 0;
        while (l1 < n && idx < n){
            nums[idx] = nums[l1];
            l1++; idx++;
            k++;
            while (l1 < n && nums[l1] == nums[l1-1]){
                l1++;
            }
        }
        return k;
    }
};