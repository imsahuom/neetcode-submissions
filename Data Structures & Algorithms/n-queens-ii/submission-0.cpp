class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& board, int i, int n){
        //we got to outside without violation
        if (i>= n){ans++; return;}
        //find if there any valid posn in ith row i.e. board[i][j] == '1' ??
        for(int j=0; j<n; j++){
            if (board[i][j] == 0) continue;
            auto dummy = board;
            //now this queen is placed at board [i][j] so we need to clear all [k][j]
            for(int k=i+1; k<n; k++) board[k][j] = 0;
            //we need to clear diagonals too
            int d = 1;
            while (i + d < n && j + d < n){
                board[i+d][j+d] = 0;
                d++;
            }
            d = 1;
            while(i+d <n && j-d >= 0){
                board[i+d][j-d] = 0;
                d++;
            }
            dfs(board, i+1, n);//visit next row;
            board = dummy;//make the board back again
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 1));
        dfs(board, 0, n);
        return ans;
    }
};