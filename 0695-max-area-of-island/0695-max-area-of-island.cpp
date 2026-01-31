class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // ================================
        // Approach 1: DFS
        // - Time  Complexity: O(R * C)
        //   (R is the row, C is the column. Visits each node once.)
        // - Space Complexity: O(R * C)
        //   (Worst case recursion depth.)
        // - Pros: Simple.
        // - Cons: May cause recursion stack overflow.
        // ================================
        int maxArea = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                maxArea = max(maxArea, dfs(grid, r, c));
            }
        }

        return maxArea;
    }

    // For approach 1
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        
        grid[r][c] = 0;

        return 1 + dfs(grid, r + 1, c) +
                   dfs(grid, r - 1, c) +
                   dfs(grid, r, c + 1) +
                   dfs(grid, r, c - 1);
    }
};