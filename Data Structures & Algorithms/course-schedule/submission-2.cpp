class Solution {
public:
    bool canFinish(int t, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(t);//this will help us figure out which course have no pre-req;
        vector<int> prs(t, 0);
        for(auto& v: prerequisites){
            int x = v[0], y = v[1];
            courses[y].push_back(x);//we can do x, if we do y
            prs[x]++;//x have a pre-req y;
        }
        queue<int> q;
        vector<int> done(t, 0);
        for(int i=0; i<t; i++){
            if (prs[i] == 0){
                q.push(i);
            }
        }
        //now q contains all those courses which don't have any pre-reqs
        if (q.empty()) return false;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            cout << curr << " ";
            t--;
            for(auto nex: courses[curr]){
                prs[nex]--;
                if (prs[nex] == 0){
                    //pre-req of this course is done
                    q.push(nex);
                }
            }
        }
        return t == 0;
    }
};
