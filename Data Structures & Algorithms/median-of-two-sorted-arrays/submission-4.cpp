class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int t = m + n;
        int l = -1, r = m-1;
        while (l <= r){
            int x = (l+r)/2;
            int y = t/2 - x - 2;
            int L1 = (x >= 0 ? nums1[x] : -1e9);
            int R1 = (x+1 < m ? nums1[x+1] : 1e9);
            int L2 = (y >= 0 ? nums2[y] : -1e9);
            int R2 = (y+1 < n ? nums2[y+1] : 1e9);

            if (L1 <= R2 && L2 <= R1){
                return t&1 ? min(R1, R2) : (max(L1,L2) + min(R1,R2))/2.0;
            }
            L1>R2 ? r = x-1: l = x+1;

        }
        return 0;
    }
};