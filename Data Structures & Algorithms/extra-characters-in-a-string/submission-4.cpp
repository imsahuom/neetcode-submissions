struct Node {
    Node* next[26];
    bool end = false;
    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

class Solution {
public:
    int dfs(const string& s, Node* root, int i, vector<int>& dp) {
        // Base case: reached the end of the string
        if (i >= s.size()) return 0;
        
        // Memoization check
        if (dp[i] != -1) return dp[i];

        // Choice 1: Treat the current character s[i] as an extra character
        int ans = 1 + dfs(s, root, i + 1, dp);

        // Choice 2: Try to form valid dictionary words starting at index i
        Node* curr = root;
        for (int j = i; j < s.size(); j++) {
            int char_idx = s[j] - 'a';
            // THE KILL SWITCH (Pruning): 
            // If the Trie node doesn't exist, no word can be formed. Break immediately.
            if (!curr->next[char_idx]) {
                break; 
            }
            // Move down the Trie
            curr = curr->next[char_idx];
            // If we hit the end of a valid dictionary word, branch out
            if (curr->end) {
                ans = min(ans, dfs(s, root, j + 1, dp));
            }
        }
        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // 1. Initialize the Trie Root
        Node* root = new Node();
        
        // 2. Build the Trie from the dictionary
        for (const string& word : dictionary) {
            Node* curr = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!curr->next[idx]) {
                    curr->next[idx] = new Node();
                }
                curr = curr->next[idx];
            }
            curr->end = true;
        }
        // 3. Setup DP table (-1 means uncomputed)
        vector<int> dp(s.size(), -1);
        // 4. Launch DFS
        return dfs(s, root, 0, dp);
    }
};