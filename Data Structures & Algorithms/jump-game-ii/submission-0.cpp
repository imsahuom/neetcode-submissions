class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), reach = 0, end = 0, jump = 0, i = 0;
        while (i < n-1){
            reach = max(reach, i + nums[i]);
            if (i == end){
                end = reach; 
                jump++;
            }
            i++;
        }
        return jump;
    }
};
