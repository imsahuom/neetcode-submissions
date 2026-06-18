class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        k = k%n;
        for(int i=0; i<k; i++){
            if (i >= k-i-1) break;
            swap(nums[i], nums[k-i-1]);
        }
        for(int i=k; i<n; i++){
            if (i >= n-i+k-1) break;
            swap(nums[i], nums[n-i+k-1]);
        }
    }
};