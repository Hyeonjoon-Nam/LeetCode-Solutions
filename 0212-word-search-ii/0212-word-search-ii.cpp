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
        // Approach 1: Backtracking with Trie (Multi-word Search)
        // - Time Complexity: $O(M \cdot N \cdot 4^L)$ 
        //   (M*N: board size, L: max word length. Pruning via Trie makes it much faster.)
        // - Space Complexity: $O(W \cdot L)$ 
        //   (W: number of words, L: max length. This is for storing the Trie.)
        // - Pros: Finds multiple words simultaneously; extremely efficient pruning.
        // - Cons: High memory usage for the Trie structure.
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