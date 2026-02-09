class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int t = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int currentHeight = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            t = max(t, currentHeight);
            visited[x][y] = true;

            if (x == n - 1 && y == n - 1) return t;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});
            }
        }

        return -1;
    }
};