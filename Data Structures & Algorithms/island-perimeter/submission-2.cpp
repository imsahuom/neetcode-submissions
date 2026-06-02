class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //for each island, we can have 0/1/2/4 contribution for the peri
        //so we'll do BFS, for each curr, we'll check eligible, and add
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1){
                int score = 4;
                if (i-1>=0 && grid[i-1][j] == 1){
                    score--;
                }
                if (i+1<n && grid[i+1][j] == 1){
                    score--;
                }
                if (j-1 >=0 && grid[i][j-1] == 1){
                    score--;
                }
                if (j+1 < m && grid[i][j+1] == 1){
                    score--;
                }
                ans+=score;
                }
            }
        }
        return ans;
    }
};