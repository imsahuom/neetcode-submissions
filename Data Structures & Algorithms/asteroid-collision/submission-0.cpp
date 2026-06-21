class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int d = 0;//it'll give us the posn of each shit
        stack<int> st;
        for(auto& a: asteroids){
            if (st.empty() || a > 0){
                st.push(a);
            }else{
                bool flag = true;
                while(!st.empty() && st.top() > 0){
                    int x = st.top();
                    if (x + a == 0) {st.pop(); flag = false; break;}
                    else if ( x + a > 0){
                        flag = false;
                        break;
                    }else{
                        st.pop();
                    }
                }
                if (flag) st.push(a);//hamne pura stack hi khali kar diya, 
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};