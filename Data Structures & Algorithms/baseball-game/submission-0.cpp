class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto& a: operations){
            if (a == "+"){
                int x = st.top(); st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }else if (a == "D"){
                int x = st.top();
                st.push(2*x);
            }else if (a == "C"){
                st.pop();
            }else{
                st.push(stoi(a));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};