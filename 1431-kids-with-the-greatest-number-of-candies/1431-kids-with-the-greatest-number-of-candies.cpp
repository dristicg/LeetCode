class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;

        // find max
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }

        vector<bool> result;

        // check each kid
        for (int i = 0; i < candies.size(); i++) {
            result.push_back(candies[i] + extraCandies >= maxCandies);
        }

        return result;
    }
};
