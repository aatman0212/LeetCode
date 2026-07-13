class Solution {
public:
    int maxArea = 0;
    vector<vector<bool>> visited;

    int helper(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 ||
            i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;

        int area = 1;

        area += helper(grid, i + 1, j);
        area += helper(grid, i - 1, j);
        area += helper(grid, i, j + 1);
        area += helper(grid, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        visited = vector<vector<bool>>(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = helper(grid, i, j);
                    maxArea = max(maxArea, area);
                }

            }
        }

        return maxArea;
    }
};