class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = min_element(nums.begin(), nums.end()) - nums.begin();
        int itr = 0;
        while (nums[(l-1+n)%n] == nums[(l+n)%n]){
            l--;
            itr++;
            if (itr>=n) break;//all elements may be equal leave this here
        }
        if (l < 0 )l+=n;
        int r = l + n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            // cout << l << " " << r << endl;
            if (nums[mid%(n)] == target) return true;
            else if (nums[mid%n] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};