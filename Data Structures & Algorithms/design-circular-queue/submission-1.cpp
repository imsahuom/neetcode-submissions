struct Node{
    int val;
    Node* next;
    Node(int key){
        val = key;
        next = nullptr;
    }
};
class MyCircularQueue {
    int p  = 0;
    int maxi = 0;
    Node* head;
    Node* tail;
public:
    MyCircularQueue(int k) {
        maxi = k;
        head = nullptr;
        tail = nullptr;
    }
    
    bool enQueue(int value) {
        if (p >= maxi) return false;
        Node* dumm = new Node(value);
        p++;
        if(!head){
            head = dumm;
            tail = dumm;
        }else{
            tail->next = dumm;
            tail = tail->next;
        }
        return true;
    }
    
    bool deQueue() {
        if (p<=0) return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        p--;

        if (head == nullptr) tail = nullptr;
        return true;
    }

    int Front() {
        if (head) return head->val;
        return -1;
    }
    
    int Rear() {
        if (tail) return tail->val;
        return -1;
    }
    
    bool isEmpty() {
        return p == 0;
    }
    
    bool isFull() {
        return p == maxi;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */