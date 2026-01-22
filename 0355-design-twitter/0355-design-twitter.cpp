class Twitter {
public:
    // ================================
    // Approach 1: Timestamped Min-Heap
    // - Time  Complexity: 
    //   Post: O(1)
    //   getNewsFeed: O(F * T * log10) (followers, average tweets per user)
    //   Follow/Unfollow: O(1) average
    // - Space Complexity: O(U + T)
    //   (U: total relationships, T: total tweets stored in memory.)
    // - Pros: Accurate chronological sorting using global timestamp.
    // - Cons: getNewsFeed becomes slow if a user follows many people with thousands of tweets
    // ================================
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timeStamp = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& t : tweets[userId]) {
            minHeap.push(t);
            if (minHeap.size() > 10) minHeap.pop();
        }

        for (int followeeId : following[userId]) {
            int count = 0;
            for (auto it = tweets[followeeId].rbegin(); it != tweets[followeeId].rend() && count < 10; ++it) {
                minHeap.push(*it);
                if (minHeap.size() > 10) minHeap.pop();
                count++;
            }
        }

        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
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