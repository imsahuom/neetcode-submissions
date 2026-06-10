class Solution {
public:
bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> inDegree(V, 0); 
    queue<int> q; 
    int visited = 0;           
    for (int u = 0; u < V; ++u){
        for (int v : adj[u]){
            inDegree[v]++;
        }
    }for (int u = 0; u < V; ++u){
        if (inDegree[u] == 0){
            q.push(u);
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        visited++;
        for (int v : adj[u]){
            inDegree[v]--;
            if (inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    return visited != V;
}
    string longestpath(set<pair<char, char>>& s){
        //given edges u, v in a directed graph, how to find out the longest path from source to sink 
        vector<vector<int>> adj(26);
        vector<int> source(26, -1);
        for(auto& [x, y]: s){
            adj[x-'a'].push_back(y-'a');
            if(source[x-'a'] == -1) source[x-'a'] = 0;
            source[y-'a']++;//you can reach y, it can't be source, it's in-degree increases
        }
        if (isCyclic(adj)) return "32";
        vector<int> dist(26, -1);
        priority_queue<pair<int, int>> pq;//max_dist, node
        for(int i=0; i<26; i++){
            if (source[i] == 0){
                pq.push({0, i});
            }
        }
        while(!pq.empty()){
            auto [d, n] = pq.top(); pq.pop();
            if (d < dist[n]) continue;
            dist[n] = d;
            for(auto& f: adj[n]){
                if (dist[f] < d + 1){
                    pq.push({d+1, f});
                }
            }
        }
        //now we'll get the dist, each index with it's dist
        vector<pair<int, char>> dict;
        for(int i=0; i<26; i++){
            if(dist[i] == -1) continue;
            dict.push_back({dist[i], 'a'+i});
        }
        sort(dict.begin(), dict.end());
        string ans = "";
        for(auto& [d, c]: dict) ans += c;
        return ans;
    }
    string foreignDictionary(vector<string>& words) {
        set<pair<char, char>> s;
        unordered_map<char, int> mp;
        int n = words.size();
        for(int i=0; i<n; i++){
            string a = words[i];
            for(auto& c: a) mp[c]++;
            for(int j=i+1; j<n; j++){
                string b = words[j];
                int ni = words[i].length(), nj = words[j].length();
                int x = 0;
                while(x<ni && x<nj){
                    if (a[x] != b[x]){
                        //a mismatch found, a[x] comes before b[x]
                        s.insert({a[x], b[x]});
                        x++;
                        break;
                    }
                    x++;
                    if (x < ni && x == nj){
                        //b khtm ho gaya, while a mein kuch  letter bache hai
                        return "";
                    }
                }
            }
        }
        string ans = longestpath(s);
        if (ans == "32") return "";
        for(auto& a: ans) mp[a] = -1;
        for(auto& [c, i]: mp){
            // cout << c << " ";
            if (i != -1) ans.push_back(c);
        }
        return ans;
    }
};
