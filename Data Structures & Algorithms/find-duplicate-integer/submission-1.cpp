class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            nums[(nums[i])%n - 1] += n;
        }   
        int ans = 0;
        for (int i=0; i<n; i++){
            if (nums[i] >= 2*n){
                ans = i+1; break;
            }
        }  
        return ans;
    }
};
