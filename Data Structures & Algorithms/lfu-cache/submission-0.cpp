struct Node{
    int key;
    int val;
    int freq;
    list<Node*>::iterator it;

    Node(int k,int v): key(k), val(v), freq(1){}
};

class LFUCache {
    unordered_map<int, Node*> mp;
    unordered_map<int, list<Node*>> freq_mp;
    int p = 0;
    int maxi;
    int min_freq = 0;
public:
    LFUCache(int capacity) {
        maxi = capacity;
    }
    void update(Node* node) {
        int oldFreq = node->freq;

        freq_mp[oldFreq].erase(node->it);

        if (oldFreq == min_freq && freq_mp[oldFreq].empty())
            min_freq++;

        node->freq++;

        freq_mp[node->freq].push_back(node);
        node->it = prev(freq_mp[node->freq].end());
    }
    int get(int key) {
        if (!mp.count(key)) return -1;

        update(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (maxi == 0) return;
        if (mp.count(key)) {
            mp[key]->val = value;
            update(mp[key]);
            return;
        }
        if (p == maxi) {

            Node* victim = freq_mp[min_freq].front();

            freq_mp[min_freq].pop_front();

            mp.erase(victim->key);

            delete victim;

            p--;
        }
        p++;
        Node* node = new Node(key, value);

        mp[key] = node;

        freq_mp[1].push_back(node);

        node->it = prev(freq_mp[1].end());

        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */