# Construct Quad Tree
class Solution {
public:
     Node* construct(vector<vector<int>>& grid) {
        return getNode(grid, 0, 0, grid.size());
    }

    Node* getNode(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return new Node(grid[x][y], true);
        }

        if (isLeaf(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        }

        int leafSize = n / 2;

        auto topL = getNode(grid, x, y, leafSize);
        auto topR = getNode(grid, x, y + leafSize, leafSize);
        auto bottomL = getNode(grid, x + leafSize, y, leafSize);
        auto bottomR = getNode(grid, x + leafSize, y + leafSize, leafSize);

        return new Node(grid[x][y], false, topL, topR, bottomL, bottomR);
    }

    bool isLeaf(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[x + i][y + j] != val) {
                    return false;
                }
            }
        }

        return true;
    }
};
