class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: BFS from all thieves to calculate min distance for each cell
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Binary search for maximum safeness factor
        int left = 0, right = n * n;
        int res = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(isPossible(dist, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    bool isPossible(vector<vector<int>>& dist, int safeness) {
        int n = dist.size();
        if(dist[0][0] < safeness) return false;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(x == n - 1 && y == n - 1) return true;
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && dist[nx][ny] >= safeness) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
};