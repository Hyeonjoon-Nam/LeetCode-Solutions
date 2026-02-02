class Solution {
private:


public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // ================================
        // Approach 1: BFS
        // - Time  Complexity: O(M * N)
        //   (Every cell is visited once.)
        // - Space Complexity: O(M * N)
        //   (In the worst case, the queue can hold all cells.)
        // - Pros: Guarantees the shortest distance upon the first visit.
        // - Cons: Requires O(M*N) extra space for the queue.
        // ================================
        if (rooms.empty()) return;

        queue<pair<int, int>> q;

        for (int r = 0; r < rooms.size(); r++) {
            for (int c = 0; c < rooms[0].size(); c++) {
                if (rooms[r][c] == 0) q.push({r, c});
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto[r, c] = q.front();
            q.pop();

            for (auto[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < rooms.size() && nc >= 0 && nc < rooms[0].size() && rooms[nr][nc] == INT_MAX) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};