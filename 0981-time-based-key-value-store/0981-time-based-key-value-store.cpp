class TimeMap {
public:
    // ================================
    // Approach 1: Hash Map + Binary Search
    // - Time  Complexity
    //   - set: O(1) amortized
    //   - get: O(log N) (Binary search on the vector of timestamps)
    // - Space Complexity: O(M)
    //   (M is the total number of set operations stored across all keys)
    // - Pros: Optimal time for get(); cache-friendly due to std::vector
    // - Cons: 
    // ================================
    unordered_map<string, vector<pair<int, string>>> timemap;
public:
    TimeMap() {
        timemap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (timemap.find(key) == timemap.end()) return "";

        auto& v = timemap[key];

        auto it = upper_bound(v.begin(), v.end(), timestamp, [](int t, const pair<int, string>& element) {
            return t < element.first;
        });

        if (it == v.begin()) return "";
        
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */