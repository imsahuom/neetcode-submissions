class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int l = 0, n = nums.size();
       int st = nums[0];
       for(int i=0; i<n; i++){
            if(nums[i] == st) l++;
            else{
                st = nums[i]; 
                l = 1;
            }
            if (l > n/2) return st;
       } 
       return st;
    }
};