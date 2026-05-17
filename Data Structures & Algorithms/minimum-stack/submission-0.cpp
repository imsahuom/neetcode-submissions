class MinStack {
    stack<pair<int, int>> st;
    int lastmini = 2147483647;
    int size;
public:
    MinStack() {
        st;
        size = 0;
    }
    
    void push(int val) {
        st.push({val, min(lastmini, val)});
        lastmini = min(lastmini, val);
        size++;
    }
    
    void pop() {
        st.pop();
        size--;
        if (size > 0) lastmini = st.top().second;
        else lastmini = 2147483647;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */