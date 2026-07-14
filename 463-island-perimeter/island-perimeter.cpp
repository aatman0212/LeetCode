class Solution {
public:
    vector<vector<bool>> visited;

    int helper(vector<vector<int>>& grid, int i, int j) {

        // Out of bounds contributes 1 to perimeter
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 1;
        }

        // Water contributes 1 to perimeter
        if (grid[i][j] == 0) {
            return 1;
        }

        // Already visited land contributes nothing
        if (visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;

        return helper(grid, i + 1, j)
             + helper(grid, i - 1, j)
             + helper(grid, i, j + 1)
             + helper(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        visited = vector<vector<bool>>(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    return helper(grid, i, j);
                }

            }
        }

        return 0;
    }
};