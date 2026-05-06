class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        // Simulate gravity for each row
        for (int i = 0; i < m; ++i) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    empty = j - 1;
                } else if (box[i][j] == '#') {
                    if (empty != j) {
                        box[i][empty] = '#';
                        box[i][j] = '.';
                    }
                    empty--;
                }
            }
        }
        // Rotate the box 90 degrees clockwise
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][m - 1 - i] = box[i][j];
            }
        }
        return res;
    }
};