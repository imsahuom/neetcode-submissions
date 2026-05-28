struct Node{
    Node* next[26];
    bool end = false;
    Node(){
        for(int i=0; i<26; i++) next[i] = nullptr;
    }
};

class WordDictionary {
    Node* start;
public:
    WordDictionary() {
        start = new Node();
    }
    
    void addWord(string word) {
        Node* curr = start;
        for(auto c: word){
            if (!curr->next[c-'a']) curr->next[c-'a'] = new Node();
            curr = curr->next[c-'a'];
        }
        curr->end = true;
    }
    bool help(const string& word, int i, Node* curr){
        if (i >= word.length()) return curr->end;
        if (word[i] != '.'){
            if (!curr->next[word[i] - 'a']) return false;
            else{
                return help(word, i+1, curr->next[word[i] - 'a']);
            }
        }else{
            bool ans = false;
            for(int j=0; j<26; j++){
                if (curr->next[j]){
                    ans = (ans | help(word, i+1, curr->next[j]));
                }
                if(ans) return ans;
            }
            return ans;
        }
        return true;
    }
    bool search(string word) {
        Node* curr = start;
        return help(word, 0, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */