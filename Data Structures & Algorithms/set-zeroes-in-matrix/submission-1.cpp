class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows, col;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (matrix[i][j] == 0){rows.push_back(i); col.push_back(j);}
            }
        }
        for(auto& r: rows){
            for(int j=0; j<m;j++) matrix[r][j] = 0;
        }
        for(auto& c: col){
            for(int i=0; i<n; i++) matrix[i][c] = 0;
        }
    }
};
