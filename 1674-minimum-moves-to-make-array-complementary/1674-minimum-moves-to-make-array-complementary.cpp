class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);

            // Initially assume 2 moves
            diff[2] += 2;

            // 1 move range starts
            diff[low + 1] -= 1;

            // 0 move at exact sum
            diff[a + b] -= 1;

            // back to 1 move
            diff[a + b + 1] += 1;

            // back to 2 moves
            diff[high + limit + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for(int s = 2; s <= 2 * limit; s++) {

            moves += diff[s];

            ans = min(ans, moves);
        }

        return ans;
    }
};