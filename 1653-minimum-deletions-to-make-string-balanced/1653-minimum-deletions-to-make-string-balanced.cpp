class Solution {
public:
    int minimumDeletions(string s) {
        // int n = s.size();
        // int ans = n;  // max possible deletions

        // for (int i = 0; i <= n; i++) {
        //     int countB = 0;
        //     int countA = 0;

        //     // count 'b' in left part [0..i-1]
        //     for (int j = 0; j < i; j++) {
        //         if (s[j] == 'b') countB++;
        //     }

        //     // count 'a' in right part [i..n-1]
        //     for (int j = i; j < n; j++) {
        //         if (s[j] == 'a') countA++;
        //     }

        //     ans = min(ans, countB + countA);
        // }

        // return ans;
        int countB = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else { // c == 'a'
                deletions = min(deletions + 1, countB);
            }
        }

        return deletions;
    }
};
