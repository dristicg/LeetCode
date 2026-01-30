class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> result;

        // store allowed characters
        for (int i = 0; i < allowed.length(); i++) {
            result.insert(allowed[i]);
        }

        int count = 0;

        // check each word
        for (int i = 0; i < words.size(); i++) {
            bool valid = true;

            for (int j = 0; j < words[i].length(); j++) {
                if (!result.count(words[i][j])) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};
