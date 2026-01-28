class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // check by skipping left
                int l1 = left + 1, r1 = right;
                while (l1 < r1 && s[l1] == s[r1]) {
                    l1++;
                    r1--;
                }

                // check by skipping right
                int l2 = left, r2 = right - 1;
                while (l2 < r2 && s[l2] == s[r2]) {
                    l2++;
                    r2--;
                }

                return l1 >= r1 || l2 >= r2;
            }
        }
        return true;
    }
};
