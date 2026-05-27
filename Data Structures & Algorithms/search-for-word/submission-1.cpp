class Solution {
public:
    int find(vector<vector<char>>& board, int x, int y, int i,const string& word){
        if (i >= word.size()) return 1;
        //choice1-right
        if (x+1 < board.size() && board[x+1][y] == word[i]){
            board[x+1][y] = '*';
            if (find(board, x+1, y, i+1, word)) return 1;
            board[x+1][y] = word[i];
        }
        //choice1-left
        if (x-1 >= 0 && board[x-1][y] == word[i]){
            board[x-1][y] = '*';
            if (find(board, x-1, y, i+1, word)) return 1;
            board[x-1][y] = word[i];
        }
        //choice1-down
        if (y+1 < board[0].size() && board[x][y+1] == word[i]){
            board[x][y+1] = '*';
            if (find(board, x, y+1, i+1, word)) return 1;
            board[x][y+1] = word[i];
        }
        //choice1-up
        if (y-1 >= 0 &&  board[x][y-1] == word[i]){
            board[x][y-1] = '*';
            if (find(board, x, y-1, i+1, word)) return 1;
            board[x][y-1] = word[i];
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int x=0; x<board.size(); x++){
            for(auto y=0; y<board[0].size(); y++){
                if(board[x][y] == word[0]){
                    board[x][y] = '*';
                    if(find(board, x, y, 1, word)) return true;
                    board[x][y] = word[0];
                }
            }
        }
        return false;
    }
};