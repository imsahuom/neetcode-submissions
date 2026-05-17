class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Change stack type to int to avoid repeated string conversions
        stack<int> st;
        
        for (const string& c : tokens) {
            // Check if the token is an operator
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                // Pop the operands
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                // Perform the operation and push the raw integer back
                if (c == "+") st.push(b + a);
                else if (c == "-") st.push(b - a);
                else if (c == "*") st.push(b * a);
                else if (c == "/") st.push(b / a);
            } else {
                // It's a number: convert it ONCE and push it
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};