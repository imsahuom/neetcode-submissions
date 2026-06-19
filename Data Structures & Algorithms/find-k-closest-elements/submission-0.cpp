class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //so every integer has a score in this array
        int n = arr.size();
        if (x <= arr[0]){
            return vector<int>(arr.begin(), arr.begin() + k);
        }else if (x >= arr[n-1]){
            return vector<int>(arr.end()-k, arr.end());
        }else{
            int l = 0, r = n-1;
            while (l < n && arr[l] < x) l++;
            while (r >=0 && arr[r] > x) r--;
            //now we've left boundary of x and right boundary of x;
            while (l <= r) l++;
            vector<int> ans;
            while (l<n && r>=0 && ans.size() < k){
                if (abs(arr[l] - x) < abs(arr[r] - x)){
                    ans.push_back(arr[l]);
                    l++;
                }else{
                    ans.push_back(arr[r]); r--;
                }
            }
            while(r >=0 && ans.size() < k) {
                ans.push_back(arr[r]); r--;
            }
            while (l<n && ans.size() < k){
                ans.push_back(arr[l]); l++;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }
};