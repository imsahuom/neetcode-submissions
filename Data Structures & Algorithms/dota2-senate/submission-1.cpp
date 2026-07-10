class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> l, r;
        for(int i=0; i<n; i++){
            if (senate[i] == 'R') l.push(i);
            else r.push(i);
        }
        while(!l.empty() && !r.empty()){
            int c1 = l.front(), c2 = r.front();
            l.pop();
            r.pop();
            if (c1 < c2){
                l.push(n+c1);
            }else{
                r.push(n+c2);
            }
        }
        if (l.size()) return "Radiant";
        return "Dire";
    }
};