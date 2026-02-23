class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        int n = s.length();

        for (int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
        }

        return seen.size() == (1 << k);
    }
};