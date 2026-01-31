struct TrieNode {
    TrieNode* children[26];
    string* word;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = nullptr;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // ============================================================
        // Approach 1: Backtracking with Trie
        // - Time Complexity: O(M * 4 * 3^(L-1))
        //   (M: total board cells, L: max word length)
        // - Space Complexity: O(N)
        //   (N: total number of characters in the word list)
        // - Pros: Simultaneous multi-word search with prefix pruning.
        // - Cons: High memory overhead due to Trie node allocations.
        // ============================================================
        TrieNode* root = buildTrie(words);
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

private:
    // For approach 1
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int i = c - 'a';
                if (!curr->children[i])
                    curr->children[i] = new TrieNode();
                curr = curr->children[i];
            }
            curr->word = &w;
        }
        return root;
    }

    // For approach 1
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* p, vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !p->children[ch - 'a']) return;

        p = p->children[ch - 'a'];
        if (p->word) {
            res.push_back(*(p->word));
            p->word = nullptr;
        }

        board[r][c] = '#';

        if (r > 0) dfs(board, r - 1, c, p, res);
        if (r < board.size() - 1) dfs(board, r + 1, c, p, res);
        if (c > 0) dfs(board, r, c - 1, p, res);
        if (c < board[0].size() - 1) dfs(board, r, c + 1, p, res);
        
        board[r][c] = ch;
    }
};