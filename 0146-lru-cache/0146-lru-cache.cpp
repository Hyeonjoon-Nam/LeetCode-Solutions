class LRUCache {
    // ================================
    // Approach 1: Hash Map + Doubly Linked List
    // - Time  Complexity: O(1)
    //   (Hash map provides O(1) access, and list allows O(1) movement via splice)
    // - Space Complexity: O(capacity)
    //   (Stores at most 'capacity' number of items in both map and list)
    // - Pros: Optimal time complexity. Splice avoids expensive memory reallocations
    // - Cons: Not cache-friendly
    // ================================
private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) : capacity(capacity) {
  
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
        } else {
            if (cacheList.size() == capacity) {
                int keyToRemove = cacheList.back().first;
                cacheMap.erase(keyToRemove);
                cacheList.pop_back();
            }
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */