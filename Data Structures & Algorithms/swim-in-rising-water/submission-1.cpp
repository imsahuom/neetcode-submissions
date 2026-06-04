class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(int i , int j , int n , int m){
        if(i<0||i>=n||j<0||j>=m)return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
       int n= grid.size();
       int m = grid[0].size();

       vector<vector<int>>res(n,vector<int>(m,INT_MAX));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       pq.push({grid[0][0],{0,0}});
       
       res[0][0]=grid[0][0];
       while(!pq.empty()){
        pair<int,pair<int,int>>p = pq.top();
        pq.pop();
        int money = p.first;
        int row = p.second.first;
        int col = p.second.second;
        if(money>res[row][col])continue;
        for(int k=0;k<4;k++){
            int r=row+x[k];
            int c= col+y[k];
            if(row == n - 1 && col == m - 1) return money;
            if(!valid(r,c,n,m))continue;
            int newM = max(money,grid[r][c]);
            if(newM<res[r][c]){
                res[r][c]=newM;
                pq.push({newM,{r,c}});
            }
        }
       }
       return res[n-1][m-1];
    }
};