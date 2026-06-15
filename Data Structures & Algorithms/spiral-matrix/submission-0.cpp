class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int dir = 0;//0-r, 1-d, 2-l, 3-u
        //we'll make visited nodes = 101
        int flag = true;
        int x = 0, y = 0;
        while(flag){
            if (dir == 0){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                if (y+1 < m && matrix[x][y+1] != 101) y++;
                else if(x+1 < n && matrix[x+1][y] != 101 ){
                    x++;
                    dir = 1;
                }else flag = false;
            }else if (dir == 1){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                if (x+1 < n && matrix[x+1][y] != 101) x++;
                else if (y-1 >= 0 && matrix[x][y-1] != 101){
                    y--;
                    dir = 2;
                }else flag = false;
            }else if (dir == 2){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                if (y-1 >= 0 && matrix[x][y-1] != 101)y--;
                else if (x-1 >= 0 && matrix[x-1][y] != 101){
                    x--;
                    dir = 3;
                }else flag = false;
            }else{
                ans.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                if (x-1 >= 0 && matrix[x-1][y] != 101) x--;
                else if(y+1 < m && matrix[x][y+1] != 101 ){
                    y++;
                    dir = 0;
                }else flag = false;
            }
        }
        // for(auto& v: matrix){
        //     for(auto& y: v) cout << y << " ";
        //     cout << endl;
        // }
        return ans;
    }
};
