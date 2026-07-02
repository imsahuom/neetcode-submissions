class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //out of all the eligible projects choose the one with max profit
        vector<pair<int, int>> pr; int n = profits.size();
        for(int i = 0; i<n; i++){
            pr.push_back({capital[i], profits[i]});
        }
        sort(pr.begin(), pr.end());
        int done = 0; int i = 0;
        priority_queue<int> pq;
        while (done < k){
            while (i < n && pr[i].first <= w){
                pq.push(pr[i].second);//we can do this projects
                i++;
            }
            //pq contains all the doable project, so do the one with max profit
            if (pq.empty()) break;//NO doable project
            w += pq.top();
            pq.pop();
            done++;//do the project, gain the profit
        }
        return w;
    }
};