class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int rot = 0; rot < 4; ++rot) {
            if (mat == target) return true;
            // Rotate mat by 90 degrees clockwise
            int n = mat.size();
            vector<vector<int>> rotated(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    rotated[j][n - 1 - i] = mat[i][j];
                }
            }
            mat = rotated;
        }
        return false;
    }
};