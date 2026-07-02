class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = tasks.size();
        for(int i=0; i<n; i++){
            pq.push({tasks[i][0], tasks[i][1], i});
        }
        vector<int> ans;
        int time = 1;
        int itr = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        while(itr < n){
            if (q.empty() && pq.empty()) break;
            if (q.empty() && time < pq.top()[0]) time++;//there's no task to finish, neither is eligible
            else{
                while(!pq.empty() && time >= pq.top()[0]){
                    q.push({pq.top()[1], pq.top()[2]});
                    pq.pop();
                }//now we've all the eligible tasks
                time += q.top()[0];
                ans.push_back(q.top()[1]);
                q.pop();
                itr++;//we finished a task
            }
        }
        return ans;
    }
};