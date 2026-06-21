class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        for(int i=0; i<n;){
            if (path[i] == '/'){
                i++;
                continue;
            }else if (path[i] == '.'){
                string curr = "";
                while(i<n && path[i] != '/'){
                    curr += path[i];
                    i++;
                }
                if (curr == ".") continue;
                else if (curr == ".."){
                    if (st.size() < 1) continue;//already at root directory
                    st.pop();//move to parent directory
                }else{
                    st.push(curr);
                }
            }else{
                string curr = "";
                while(i<n && path[i] != '/'){
                    curr += path[i];
                    i++;
                }
                st.push(curr);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = "/"+ st.top()+ ans;
            st.pop();
        }
        if (ans == "") ans = "/";
        return ans;
    }
};