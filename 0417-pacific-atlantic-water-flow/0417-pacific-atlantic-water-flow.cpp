class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // ================================
        // Approach 1: BFS
        // - Time  Complexity: O(M * N)
        //   (Visits each noce at most once.)
        // - Space Complexity: O(M * N)
        //   (M * N size of space required for pQ, aQ, pVisited, aVisited, res)
        // - Pros: Optimal.
        // - Cons: Requires extra space.
        // ================================
        vector<vector<int>> res;

        int m = heights.size();
        int n = heights[0].size();

        vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        queue<pair<int, int>> pQ;
        vector<vector<bool>> pVisited(m, vector<bool>(n, false));

        queue<pair<int, int>> aQ;
        vector<vector<bool>> aVisited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pQ.push({i, 0}); pVisited[i][0] = true;
            aQ.push({i, n - 1}); aVisited[i][n-1] = true;
        }
        for (int i = 0; i < n; i++) {
            pQ.push({0, i}); pVisited[0][i] = true;
            aQ.push({m - 1, i}); aVisited[m-1][i] = true;
        }

        while(!pQ.empty()) {
            auto[r, c] = pQ.front(); pQ.pop();

            for (auto[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || pVisited[nr][nc]) continue;

                if (heights[r][c] <= heights[nr][nc]) {
                    pVisited[nr][nc] = true;
                    pQ.push({nr, nc});
                }
            }
        }

        while(!aQ.empty()) {
            auto[r, c] = aQ.front(); aQ.pop();

            for (auto[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || aVisited[nr][nc]) continue;

                if (heights[r][c] <= heights[nr][nc]) {
                    aVisited[nr][nc] = true;
                    aQ.push({nr, nc});
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pVisited[r][c] && aVisited[r][c])
                    res.push_back({r, c});
            }
        }
        return res;
    }
};