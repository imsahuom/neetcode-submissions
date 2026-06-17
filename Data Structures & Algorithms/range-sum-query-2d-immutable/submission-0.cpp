class NumMatrix {
    vector<vector<int>> a;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
        int n = a.size(), m = a[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                a[i][j] += a[i][j-1];
            }
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                a[i][j] += a[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1 = a[row2][col2];
        int s2 = 0, s3 = 0, s4 = 0;
        if (row1-1>=0 && col1-1>=0) s2 = a[row1-1][col1-1];
        if (row1-1>=0) s3 = a[row1-1][col2];
        if (col1-1>=0) s4 = a[row2][col1-1];
        return s1 + s2 - s3 - s4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */