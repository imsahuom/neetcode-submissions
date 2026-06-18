class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), cnt = 0;
        int ans = 0;
        int l = 0, r = n-1;
        while(cnt < n){
            if (people[r] + people[l] <= limit){
                //we can transport these two sluts
                cnt += 2;
                ans++;
                l++; r--;
            }else if (people[r] <= limit){
                cnt += 1;
                ans++;
                r--;
            }
        }
        return ans;
    }
};