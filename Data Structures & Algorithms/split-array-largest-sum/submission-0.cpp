class Solution {
public:
    bool valid(vector<int>& nums, int k, int limit){
        int n = nums.size();
        for(int i=0; i<n;){
            if (nums[i] > limit) return false;
            int sum = 0;
            while(i<n && sum + nums[i] <= limit){
                sum+=nums[i];
                i++;
            }
            k--;//we've used one bag here
        }
        return (k>=0);
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 1e9;
        while(l<=r){
            int m = l + (r-l)/2;
            // cout << m << " ";
            if (valid(nums, k, m)) r = m-1;
            else l = m+1;
        }
        return l;
    }
};