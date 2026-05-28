struct Node{
    Node* links[26];
    bool end = false;

    bool check(char ch){
        return (links[ch-'a'] != 0);
    }
    void set(char ch){
        links[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        end = true;
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
        for(int i=0; i<word.length(); i++){
            if (!curr->check(word[i])){
                curr->set(word[i]);
            }
            curr = curr->get(word[i]);
        }
        curr->setend();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++){
            if (!curr->check(word[i])) return false;
            curr = curr->get(word[i]);
        }
        return curr->end;
    }
    
    bool startsWith(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++){
            if (!curr->check(word[i])) return false;
            curr = curr->get(word[i]);
        }
        return true;
    }
};
