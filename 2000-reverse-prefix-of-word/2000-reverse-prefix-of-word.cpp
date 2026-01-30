class Solution {
public:
    string reversePrefix(string word, char ch) {

        int idx = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                idx = i;
                break;
            } 
        }

         if (idx == -1) {
            return word;
        }
        
        int left = 0, right = idx;
        while (left < right) {
            swap(word[left], word[right]);
            left = left + 1;
            right = right - 1;
        }
        return word;
    }
};