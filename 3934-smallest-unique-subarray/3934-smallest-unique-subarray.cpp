class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        // Build Suffix Array
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> x = {
                    rank[a], (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> y = {
                    rank[b], (b + k < n) ? rank[b + k] : -1
                };

                temp[b] = temp[a] + (x != y);
            }

            rank.swap(temp);

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP Array using Kasai's Algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0) h--;
        }

        // Find the shortest unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            int mx = max(lcp[r], (r + 1 < n ? lcp[r + 1] : 0));

            int len = mx + 1;

            if (len <= n - i)
                ans = min(ans, len);
        }

        return ans;
    }
};