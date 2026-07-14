class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }

            }
        }
        if (fresh == 0)
            return 0;
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                for (int k = 0; k < 4; k++) {
                    int newRow = row + dr[k];
                    int newCol = col + dc[k];
                    if (newRow < 0 || newCol < 0 ||
                        newRow >= grid.size() ||
                        newCol >= grid[0].size()) {
                        continue;
                    }
                    if (grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        fresh--;

                        q.push({newRow, newCol});
                    }
                }
            }
            if (!q.empty()) {
                minutes++;
            }
        }

        if (fresh > 0)
            return -1;

        return minutes;
    }
};