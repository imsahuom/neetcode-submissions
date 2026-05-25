class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(auto c: tasks) count[c-'A']++;
        // for(auto i: count) cout << i << " ";
        int ans = 0, total = tasks.size();
        while(total > 0){
            //we've n spaces, let's find out how much we can fill
            int cnt = 0;
            sort(count.rbegin(), count.rend()); 
            for(int i=0; i<26; i++){
                if (count[i] <= 0) continue;
                cnt++;
                count[i]--;
                if (cnt > n) break;
            }
            if (cnt == 0) break;
            total -= cnt;
            if (cnt <= n && total != 0) ans+= n+1;
            else ans += cnt;
        }
        return ans;
    }
};