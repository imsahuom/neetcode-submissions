class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 1;
        for(int i=0; i<n-1; i++){
            if (arr[i] < arr[i+1]) arr[i] = 1;
            else if (arr[i] == arr[i+1]) arr[i] = 0;
            else arr[i] = -1;
        }
        arr.pop_back();
        //now find max subarray with 1, -1, 1, -1.. pattern or -1, 1, -1, ...
        int len = 0; int ans = 1; int last = 0;
        for(int i=0; i<n-1; i++){
            if (arr[i] == 0){
                ans = max(ans, len+1);
                len = 0;
            }else if (arr[i] == last){
                ans = max(ans, len+1);
                len = 1;
            }else{
                len++;
            }
            last = arr[i];
        }
        ans = max(ans, len+1);
        return ans;
    }
};