class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st; st.push(n-1);
        vector<int> ans(n, 0);
        for(int i=n-2; i>=0; i--){
            if (temp[i] < temp[st.top()]){
                ans[i] = st.top() - i;
                st.push(i);
            }else{
                while (!st.empty() && temp[i] >= temp[st.top()]){
                    st.pop();
                }
                if (st.empty()){ans[i] = 0;}
                else ans[i] = st.top() - i;
                st.push(i);
            }
        }
        return ans;
    }
};