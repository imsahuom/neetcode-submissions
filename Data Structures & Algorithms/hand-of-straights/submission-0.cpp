class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), k = n/groupSize; //k is no. of groups
        sort(hand.begin(), hand.end());
        vector<pair<int, int>> cards(k, {-1, 0});//track last of each group
        for(auto& h: hand){
            bool flag = false;
            for(auto& [l, s]: cards){
                if (s == groupSize) continue;
                if (l == h - 1){
                    l = h;//we just got a new card in our group
                    s++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                //need to check if any grp has last = -1, we need to place it there
                for(auto& [l, s]: cards){
                    if (l == -1){
                        l = h;
                        s++;
                        flag = true;
                        break;
                    }
                }
                if(!flag) return false;
            }
        }
        return true;
    }
};
