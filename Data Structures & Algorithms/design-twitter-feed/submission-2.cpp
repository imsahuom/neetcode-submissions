class Twitter {
    unordered_map<int, set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int clk = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({clk, tweetId});
        clk++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto u: follower[userId]){
            if (u == userId) continue;
            for(auto t: tweets[u]){
                pq.push(t);
                if (pq.size() > 10) pq.pop();
            }
        }
        for(auto t: tweets[userId]){
            pq.push(t);
            if (pq.size() > 10) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){ans.push_back(pq.top().second); pq.pop();}
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */