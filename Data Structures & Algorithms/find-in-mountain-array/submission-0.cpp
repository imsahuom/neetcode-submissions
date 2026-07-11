/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray& arr, int n){
        int l = 1, r = n-2;
        while(r>=l){
            int m = (l + r)/2;
            int left = arr.get(m-1), centre = arr.get(m), right = arr.get(m+1);
            if (left < centre && centre > right) return m;
            else if (left < centre && right > centre) l = m+1;
            else r = m-1;
        }
        return l;
    }
    int find(MountainArray& arr, int l, int r, int target){
        while(l <= r){
            int m = (l+r)/2;
            int v = arr.get(m);
            if (v == target) return m;
            else if (v < target) l = m + 1;
            else r = m-1;
        }
        return -1;
    }
    int find2(MountainArray& arr, int l, int r, int target){
        while(l <= r){
            int m = (l+r)/2;
            int v = arr.get(m);
            if (v == target) return m;
            else if (v > target) l = m + 1;
            else r = m-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int m = findPeak(arr, n);
        int l = find(arr, 0, m, target), r = find2(arr, m, n-1, target);
        // cout << l << " " << r << endl;
        if (l != -1) return l;
        if (r != -1) return r;
        return -1;
    }
};