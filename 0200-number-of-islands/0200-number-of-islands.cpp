class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // ================================
        // Approach 1: DFS
        // - Time  Complexity: O(M * N)
        //   (M: rows, N: cols. Each cell is visited at most once.)
        // - Space Complexity: O(M * N)
        //   (Worst case recursion depth if the entire grid is one island.)
        // - Pros: Simple, no extra space for a 'visited' array.
        // - Cons: Modifies the input grid, can cause stack overflow.
        // ================================
        int count = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};