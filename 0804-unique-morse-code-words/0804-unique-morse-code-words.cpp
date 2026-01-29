class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                                "--.",  "....", "..",   ".---", "-.-",  ".-..",
                                "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                                "...",  "-",    "..-",  "...-", ".--",  "-..-",
                                "-.--", "--.."};

        unordered_set<string>
            st;

        for (int i = 0; i < words.size(); i++) {
            string code = "";

            for (int j = 0; j < words[i].size(); j++) {
                code += morse[words[i][j] - 'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};