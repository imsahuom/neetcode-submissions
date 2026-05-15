class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = 0;
        int ans = 0, block = -height[r];
        while (l < n && r < n){
            if (height[r] >= height[l] && r != l){
                // cout << l << " " << r << " " << block << " " <<endl;
                ans += (r - l - 1)*min(height[r], height[l]) - block;
                l = r; block = -height[r];
            }else{
                block += height[r];
                r++;
            }
        }
        int n1 = l, l1 = n-1, r1 = n-1, b = -height[r1];//Let's go backwards :)
        while (l1 >= n1 && r1 >= n1){
            if (height[r1] >= height[l1] && l1 != r1){
                ans += (l1-r1-1)*min(height[r1], height[l1]) - b;
                l1 = r1; b = -height[r1];
            }else{
                b += height[r1];
                r1--;
            }
        }
        return ans;
    }
};
