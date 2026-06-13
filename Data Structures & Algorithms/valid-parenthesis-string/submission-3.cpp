class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, stock;
        int n = s.size();
        for(int i=0; i<n; i++){
            auto c = s[i];
            if (c == '('){
                st.push(i);
            }else if (c == ')'){
                if (st.empty()){
                    if(!stock.empty()) stock.pop();
                    else return false;// no stock & nothing on stack
                }else{
                    st.pop();//we've something on stack
                }
            }else
                stock.push({i});
        }
        //we've some stack & some * left, 
        // so stack must have these * to use, but these stars must be after the stack elments to be get used
        if (stock.size() >= st.size()){
            while(!st.empty()){
                int i = st.top(), j = stock.top();
                if (j >= i){ st.pop();stock.pop();}
                else return false;
            }
        }else{
            return false;
        }
        return true;
    }
};
