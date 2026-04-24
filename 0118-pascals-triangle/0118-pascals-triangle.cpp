class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        // base case
        if (numRows == 0) return triangle;

        // first row
        triangle.push_back({1});

        // build remaining rows
        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1, 1);   // row size = i+1, filled with 1

            // to fill middle elements
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
