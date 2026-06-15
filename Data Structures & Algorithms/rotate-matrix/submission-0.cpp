class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n-1-i; j++){
                int x = i, y = j;
                int curr = v[x][y];
                for(int k=0; k<4; k++){
                    int nx = y, ny = n-1-x;
                    int next = v[nx][ny];
                    v[nx][ny] = curr;
                    curr = next;
                    x = nx; y = ny;
                }
            }
        }
    }
};