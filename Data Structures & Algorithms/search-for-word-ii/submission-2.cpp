struct Node {
    Node* next[26] = {nullptr};
    bool end = false;
    string w = "";
};

class Solution {
public:
    Node* root = new Node();
    vector<string> ans;
    
    // Direction vectors for cleanly moving Up, Down, Left, Right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int i, int j, Node* curr) {
        char ch = board[i][j];
        int c = ch - 'a';
        
        if (curr->next[c] == nullptr) return;
        curr = curr->next[c];
        if (curr->end) {
            ans.push_back(curr->w);
            curr->end = false; 
        }

        board[i][j] = '#'; 

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            // Boundary checks aur check ki cell visited to nahi hai
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] != '#') {
                dfs(board, ni, nj, curr);
            }
        }

        board[i][j] = ch; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        bool start_chars[26] = {false};
        for (const auto& word : words) {
            Node* curr = root;
            for (char x : word) {
                int i = x - 'a';
                if (curr->next[i] == nullptr) curr->next[i] = new Node();
                curr = curr->next[i];
            }
            curr->end = true;
            curr->w = word;
            start_chars[word[0] - 'a'] = true; 
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (start_chars[board[i][j] - 'a']) {
                    dfs(board, i, j, root);
                }
            }
        }
        return ans;
    }
};