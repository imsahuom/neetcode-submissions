class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dead(10000, false), vis(10000, false);

        for (auto &s : deadends)
            dead[stoi(s)] = true;

        if (dead[0]) return -1;
        if (target == "0000") return 0;

        queue<string> q;
        q.push("0000");
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == target)
                    return steps;

                for (int i = 0; i < 4; i++) {
                    char old = cur[i];

                    // Rotate forward
                    cur[i] = (old == '9') ? '0' : old + 1;
                    int num = stoi(cur);
                    if (!dead[num] && !vis[num]) {
                        vis[num] = true;
                        q.push(cur);
                    }

                    // Rotate backward
                    cur[i] = (old == '0') ? '9' : old - 1;
                    num = stoi(cur);
                    if (!dead[num] && !vis[num]) {
                        vis[num] = true;
                        q.push(cur);
                    }

                    cur[i] = old;
                }
            }
            steps++;
        }

        return -1;
    }
};