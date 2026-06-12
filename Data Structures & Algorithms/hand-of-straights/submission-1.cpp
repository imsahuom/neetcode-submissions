class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if(n%gs != 0) return false;
        int t = n/gs;//total no. of groups needed
        sort(hand.begin(), hand.end());
        // same element can't be in more than t grps, i.e. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //will store {last, size}
        for(auto& h: hand){
            if(pq.empty()) {pq.push({h, 1}); t--;}
            else{
                auto [l, s] = pq.top(); pq.pop();
                // cout << l << " " << s << " " << h << " " << t << endl;
                if (l != h-1 && t <= 0) return false;//we can't create a new group, neither an old one is eligible
                else if (l != h-1){pq.push({h, 1}); pq.push({l, s}); t--;}//old one isn't eligible
                else{
                    s++;
                    if (s != gs) pq.push({h, s});//old group is not filled, add it back
                }
            }
        }
        
        return true;
    }
};
