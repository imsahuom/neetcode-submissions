class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> ans(2, 0);
        ans[1] = 1;
        int i = 0;
        int m = 2;
        while(ans.size() < n+1){
            if(i == m){i = 0; m*=2;}
            ans.push_back(ans[i]+1);
            i++;
        }
        return ans;
    }
};
