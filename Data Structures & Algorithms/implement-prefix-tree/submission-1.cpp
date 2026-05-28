struct Node{
    Node* links[26];
    bool end;
    Node(){
        for(int i=0; i<26; i++) links[i] = nullptr;
        end = false;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c: word){
            int i = c-'a';
            if (curr->links[i] == nullptr){
                curr->links[i] = new Node();
            }
            curr = curr->links[i];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto c: word){
            int i = c-'a';
            if (curr->links[i] == nullptr) return false;
            curr = curr->links[i];
        }
        return curr->end;
    }
    
    bool startsWith(string word) {
        Node* curr = root;
        for(auto c: word){
            int i = c-'a';
            if (curr->links[i] == nullptr) return false;
            curr = curr->links[i];
        }
        return true;
    }
};
