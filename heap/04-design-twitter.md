```cpp
class Twitter {
public:
    int timer;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        following[userId].insert(userId);

        for(auto user : following[userId]){
            if(tweets[user].empty()) continue;

            int idx = tweets[user].size() - 1;

            pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user,
                idx,
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);

            // Push previous tweet of same user
            if (idx > 0) {

                idx--;

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].erase(followeeId);
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
 ```