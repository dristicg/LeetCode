class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int colums = matrix[0].size();

        for (int j = 0; j < colums; j++) {
            int max = INT_MIN;

            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = max;
                }
            }
        }
        return matrix;
    }
};