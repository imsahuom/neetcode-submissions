class Solution {
public:
    vector<vector<int>> ans;
    void two_sum(vector<int>& nums, long long real, int l, int r, int i, int j, int n){
        //now the problem is two_sum with array nums[r+1: n];
        if (l >= r || i >= j) return;
        while (i < j){
            if (nums[i] + nums[j] == real){
                vector<int> curr = {nums[l], nums[r], nums[i], nums[j]};
                ans.push_back(curr); 
                i++; j--;
                while (i<n && nums[i] == nums[i-1]) i++;
                while (j>r && nums[j] == nums[j+1]) j--;
            }
            else if (nums[i] + nums[j] < real) i++;
            else j--;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int l=0; l<n-3;){
            for(int r = l+1; r<n-2;){
                long long real = (long long)target - nums[l] - nums[r];
                two_sum(nums, real, l, r, r+1, n-1, n);
                r++;
                while(r < n-2 && nums[r] == nums[r-1]) r++;
            }
            l++;
            while(l < n-3 && l >= 1 && nums[l] == nums[l-1]) l++;
        }
        return ans;
    }
};