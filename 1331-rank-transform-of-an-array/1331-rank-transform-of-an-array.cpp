class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> rank;
        int currRank = 1;
        for (int num : sortedArr) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currRank++;
            }
        }
        
        vector<int> res;
        for (int num : arr) {
            res.push_back(rank[num]);
        }
        return res;
    }
};