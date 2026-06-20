class MyQueue {
    stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int n = st1.size();
        for(int i=0; i<n-1; i++){
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top(); st1.pop();
        for(int i=0; i<n-1; i++){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    int peek() {
        int n = st1.size();
        for(int i=0; i<n-1; i++){
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top();
        for(int i=0; i<n-1; i++){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    bool empty() {
        return (st1.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */