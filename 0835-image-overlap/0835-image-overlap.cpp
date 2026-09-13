#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> non_zero_1;
        vector<pair<int, int>> non_zero_2;
        
        // Step 1: Store the coordinates of all 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) non_zero_1.push_back({r, c});
                if (img2[r][c] == 1) non_zero_2.push_back({r, c});
            }
        }
        
        // Step 2: Map to count the frequency of each transformation vector
        // Since coordinates are at most 30, we can encode (dr, dc) as a single integer: dr * 100 + dc
        unordered_map<int, int> transform_counts;
        int max_overlap = 0;
        
        for (auto& p1 : non_zero_1) {
            for (auto& p2 : non_zero_2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                int key = dr * 100 + dc; // Unique key for each unique shift
                
                transform_counts[key]++;
                max_overlap = max(max_overlap, transform_counts[key]);
            }
        }
        
        return max_overlap;
    }
};