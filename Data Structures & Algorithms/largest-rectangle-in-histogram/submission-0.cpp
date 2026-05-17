#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0;
        
        vector<int> left(n, 0), right(n, 0);
        stack<int> st1, st2; 
        st1.push(0);
        left[0] = -1;
        
        for(int i = 1; i < n; i++) {
            while (!st1.empty() && h[st1.top()] >= h[i]) {
                st1.pop();
            }
            left[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }
        
        st2.push(n - 1);
        right[n - 1] = n;
        
        for (int i = n - 2; i >= 0; i--) {
            while (!st2.empty() && h[st2.top()] >= h[i]) {
                st2.pop();
            }
            right[i] = st2.empty() ? n : st2.top();
            st2.push(i); 
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, h[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};