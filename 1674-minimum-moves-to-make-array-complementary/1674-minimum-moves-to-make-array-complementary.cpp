class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - 1 - i];
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            diff[2] += 2;           // assume 2 moves for all
            diff[low] -= 1;         // 1 move from low to sum
            diff[sum] -= 1;         // 0 move at sum
            diff[sum + 1] += 1;     // back to 1 move after sum
            diff[high + 1] += 1;    // back to 2 moves after high
        }

        int res = INT_MAX, curr = 0;
        for (int i = 2; i <= 2 * limit; ++i) {
            curr += diff[i];
            res = min(res, curr);
        }
        return res;
    }
};