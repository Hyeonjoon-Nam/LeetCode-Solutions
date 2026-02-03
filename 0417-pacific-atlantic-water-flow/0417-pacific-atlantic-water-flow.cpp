class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        int m = heights.size();
        int n = heights[0].size();

        vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        queue<pair<int, int>> pQ;
        vector<vector<bool>> pVisited(m, vector<bool>(n, false));

        queue<pair<int, int>> aQ;
        vector<vector<bool>> aVisited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pQ.push({i, 0});
            aQ.push({i, n - 1});
        }
        for (int i = 0; i < n; i++) {
            pQ.push({0, i});
            aQ.push({m - 1, i});
        }

        while(!pQ.empty()) {
            auto[r, c] = pQ.front(); pQ.pop();
            if (pVisited[r][c] == true) continue;
            else pVisited[r][c] = true;

            for (auto[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || pVisited[nr][nc]) continue;

                if (heights[r][c] <= heights[nr][nc]) pQ.push({nr, nc});
            }
        }

        while(!aQ.empty()) {
            auto[r, c] = aQ.front(); aQ.pop();
            if (aVisited[r][c] == true) continue;
            else aVisited[r][c] = true;

            for (auto[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || aVisited[nr][nc]) continue;

                if (heights[r][c] <= heights[nr][nc]) aQ.push({nr, nc});
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