class FreqStack {
    unordered_map<int, int> mp;
    vector<stack<int>> st;
    int maxf = 0;
public:
    FreqStack() {
        stack<int> emp;
        st.push_back(emp);
    }
    void push(int val) {
        mp[val]++;
        maxf = max(maxf, mp[val]);
        if (st.size() <= maxf){//need another stack to do this shit
            stack<int> s; s.push(val);
            st.push_back(s);
        }else{
            st[mp[val]].push(val);
        }
    }
    
    int pop() {
        int ans = st[maxf].top(); st[maxf].pop();
        mp[ans]--;//freq of this shit should reduce
        if (st[maxf].empty()){ maxf--; st.pop_back();}//there's no element with this freq;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */