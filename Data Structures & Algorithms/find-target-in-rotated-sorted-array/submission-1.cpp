class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m, n = nums.size();
        while (l < r){
            m = (l+r)/2;
            if (nums[m] < nums[r]) r= m;
            else l = m + 1;
        }
        cout << l << endl;
        //now l is the starting index;
        int left = l, right = n + l - 1;
        while (left <= right){
            m = (left+right)/2;
            // cout << left << " " << m << " " << right << endl;
            
            if (target == nums[m%n]) return m%n;
            else if (target > nums[m%n]) left = m + 1;
            else right = m -1 ;
        }
        // cout << left << " " << m << " " << right << endl;
        if (target == nums[left%n]) return left%n;
        else return -1;
    }
};