struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    // Approach 1
    unordered_set<string> s;

    // Approach 2
    TrieNode* root;

public:
    // ================================
    // Approach 1: 
    // - Time  Complexity: O()
    //   ()
    // - Space Complexity: O()
    //   ()
    // - Pros: 
    // - Cons: 
    // ================================
    
    // ================================
    // Approach 2: 
    // - Time  Complexity: O()
    //   ()
    // - Space Complexity: O()
    //   ()
    // - Pros: 
    // - Cons: 
    // ================================
    Trie() {
        // Approach 1
        // s.clear();
        
        // Approach 2
        root = new TrieNode();
    }
    
    void insert(string word) {
        // Approach 1
        // s.insert(word);
        
        // Approach 2
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        // Approach 1
        // return s.find(word) != s.end();
        
        // Approach 2
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        // Approach 1
        // for (auto& str : s) {
        //     if (str.length() < prefix.length()) continue;

        //     int p = 0;
        //     while (p < prefix.length()) {
        //         if (str[p] != prefix[p]) break;
        //         p++;
        //     }
        //     if (p == prefix.length()) return true;
        // }
        // return false;
        
        // Approach 2
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */