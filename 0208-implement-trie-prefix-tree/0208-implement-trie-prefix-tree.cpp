class Trie {
private:
    unordered_set<string> s;

public:
    Trie() {
            s.clear();
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return s.find(word) != s.end();
    }
    
    bool startsWith(string prefix) {
        for (auto& str : s) {
            if (str.length() < prefix.length()) continue;

            int p = 0;
            while (p < prefix.length()) {
                if (str[p] != prefix[p]) break;
                p++;
            }
            if (p == prefix.length()) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */