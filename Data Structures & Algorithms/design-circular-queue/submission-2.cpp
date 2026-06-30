class MyCircularQueue {
    vector<int> v;
    int maxi;
    int p = 0;
    int head;
public:
    MyCircularQueue(int k) {
        v.resize(k, -1);
        maxi = k;
        head = 0;
    }
    
    bool enQueue(int value) {
        if (p >= maxi) return false;
        v[(head + p + maxi)%maxi] = value;
        p++;
        return true;
    }
    
    bool deQueue() {
        if (p<=0) return false;
        head = (head+1)%maxi;
        p--;
        return true;
    }
    
    int Front() {
        if (p<=0) return -1;
        return v[(head+maxi)%maxi];
    }
    
    int Rear() {
        if (p<=0) return -1;
        return v[(head+p+maxi-1)%maxi];
    }
    
    bool isEmpty() {
        return p==0;
    }
    
    bool isFull() {
        return p==maxi;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(maxi);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */