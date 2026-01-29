struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
// ============================================================
    // Approach 1: Trie with DFS Backtracking
    // - Time Complexity:
    //   - addWord: O(M) where M is the word length.
    //   - search: O(M) for regular words; up to O(N * 26^M) for wildcards ".".
    // - Space Complexity:
    //   - Trie Storage: O(T) where T is total characters stored.
    //   - Search Stack: O(M) for the recursion depth.
    // - Pros: Fast word insertion and efficient wildcard pruning.
    // - Cons: Wildcard "." search can be expensive in dense Tries.
    // ============================================================
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    // For approach 1
    bool dfs(string& word, int index, TrieNode* curr) {
        if (index == word.length()) {
            return curr->isEnd;
        }

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    if (dfs(word, index + 1, curr->children[i]))
                        return true;
                }
            }
            return false;
        }
        else {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) return false;
            return dfs(word, index + 1, curr->children[idx]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */