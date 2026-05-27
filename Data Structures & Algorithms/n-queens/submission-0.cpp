class Solution {
public:
    vector<vector<string>> res;
    unordered_map<int, int> col;
    unordered_map<int, int> diag1; // row - col
    unordered_map<int, int> diag2; // row + col
    void backtrack(int n, int i, vector<string>& curr){
        if (i >= n){res.push_back(curr); return;}
        string str(n,'.');
        for(int j=0; j<n; j++){
            if (col[j] != 0) continue;
            if (diag1[(i-j)] != 0 || diag2[(i+j)] != 0) continue;
            col[j]++;
            diag1[i-j]++;
            diag2[i+j]++;
            str[j] = 'Q';
            curr.push_back(str);
            backtrack(n, i+1, curr);
            curr.pop_back();
            str[j] = '.';
            col[j]--;
            diag1[(i-j)]--;
            diag2[(i+j)]--;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        backtrack(n, 0, curr);
        return res;
    }
};