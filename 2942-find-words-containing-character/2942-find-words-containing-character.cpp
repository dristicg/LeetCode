class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            // Check if x is in words[i]
            for (char c : words[i]) {
                if (c == x) {
                    result.push_back(i);
                    break; // Move to next word after first match
                }
            }
        }
        return result;
    }
};