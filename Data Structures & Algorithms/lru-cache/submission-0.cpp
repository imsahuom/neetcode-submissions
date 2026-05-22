class LRUCache {
    int total = 0;
    int sz = 0;
public:
    struct Node {
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int x, int y) {
            key = x;
            val = y;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    void detatch(Node* n){
        sz--;
        Node* L = n->prev;
        Node* R = n->next;
        L->next = R;
        R->prev = L;
        return;
    }
    void insert(Node* n){
        sz++;
        Node* R = head->next;
        n->next = R;
        n->prev = head;
        R->prev = n;
        head->next = n;
        return;
    }
    LRUCache(int capacity) {
        total = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* n = mp[key];
        detatch(n);
        insert(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            mp[key]->val = value;
            detatch(mp[key]);
            insert(mp[key]);
            return;
        }
        if (sz >= total){
            Node* del = tail->prev;
            mp.erase(del->key);
            detatch(del);
            delete(del);
        }
        Node* n = new Node(key, value);
        mp[key] = n;
        insert(n);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */