class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;

    bool pac(vector<vector<int>>& h, int i, int j, vector<vector<int>>& v){
        if (i == 0 || j == 0) return true;
        v[i][j] = 1;
        for(int k=0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if (nx<0 || ny<0 || nx >= n || ny >= m || h[i][j] < h[nx][ny] || v[nx][ny]) continue;
            if(pac(h, nx, ny, v)) return true;
        }
        return false;
    }
    bool pact(vector<vector<int>>& h, int i, int j, vector<vector<int>>& v){
        if (i >= n-1 || j >= m-1) return true;
        v[i][j] = 1;
        for(int k=0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if (nx<0 || ny<0 || nx >= n || ny >= m || h[i][j] < h[nx][ny] || v[nx][ny]) continue;
            if(pact(h, nx, ny, v)) return true;
        }
        return false;;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size(); m = h[0].size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //check (i, j) is valid or not??
                vector<vector<int>> v1(n, vector<int>(m, 0));
                vector<vector<int>> v2(n, vector<int>(m, 0));
                if (pac(h, i, j, v1) && pact(h, i, j, v2)){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
