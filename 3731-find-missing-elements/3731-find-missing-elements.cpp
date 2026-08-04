class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        vector<int> missing_element;
        unordered_set<int> numset(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        for (int i = min + 1; i < max; i++) {
            if (numset.find(i) == numset.end()) {
                missing_element.push_back(i);
            }
        }
        return missing_element;
    }
};