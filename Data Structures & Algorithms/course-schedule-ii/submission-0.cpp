class Solution {
public:
    vector<int> findOrder(int t, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(t);
        vector<int> prs(t, 0);
        vector<int> ans;
        for(const auto& v: prerequisites){
            courses[v[1]].push_back(v[0]);
            prs[v[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<t; i++){
            if (prs[i] == 0){
                q.push(i);
            }
        }
        
        if (q.empty()) return {}; 
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            ans.push_back(curr);
            t--; // Decrement remaining courses count
            
            for(auto nex: courses[curr]){
                prs[nex]--;
                if (prs[nex] == 0){
                    q.push(nex);
                }
            }
        }
        return (t == 0) ? ans : std::vector<int>{};
    }
};