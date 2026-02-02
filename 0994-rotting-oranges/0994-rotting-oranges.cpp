class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // ================================
        // Approach 1: BFS
        // - Time  Complexity: O(M * N)
        //   (Visits each cell once)
        // - Space Complexity: O(M * N)
        //   (In the worst case, the queue can hold all cells.)
        // - Pros: Concise, optimal.
        // - Cons: Requires extra space for the queue.
        // ================================
        if (grid.empty()) return -1;
        int minute = 0;

        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    fresh++;
            }
        }

        vector<pair<int, int>> directions = {
            { -1,  0 }, {  1, 0 },
            {  0, -1 }, {  0, 1 }
        };

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto[r, c] = q.front(); q.pop();

                for (auto[dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1) continue;
                    
                    fresh--;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            minute++;
        }

        return fresh == 0 ? max(minute - 1, 0) : -1;
    }
};