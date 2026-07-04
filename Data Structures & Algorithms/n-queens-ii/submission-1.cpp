class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& cols, vector<int>& dia, vector<int>& dia2, int i, int n){
        //we got to outside without violation
        if (i>= n){ans++; return;}
        //find if there any valid posn in ith row i.e. board[i][j] == '1' ??
        for(int j=0; j<n; j++){
            if(cols[j]) continue;
            if(dia[i-j+n-1]) continue;
            if(dia2[i+j]) continue;
            cols[j] = 1;
            dia[i-j+n-1] = 1;
            dia2[i+j] = 1;
            dfs(cols, dia, dia2, i+1, n);//visit next row;
            cols[j] = 0;
            dia[i-j+n-1] = 0;
            dia2[i+j] = 0;
        }
    }
    int totalNQueens(int n) {
        vector<int> cols(n, 0);
        vector<int> dia1(2*n+1, 0), dia2(2*n+1, 0);
        dfs(cols, dia1, dia2, 0, n);
        return ans;
    }
};