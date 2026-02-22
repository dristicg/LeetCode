class Solution {
public:
    int binaryGap(int n) {
        int lastIndex = -1;
        int currentIndex = 0;
        int maxGap = 0;

        while (n > 0) {
            if (n & 1) {  // check if last bit is 1
                if (lastIndex != -1) {
                    maxGap = max(maxGap, currentIndex - lastIndex);
                }
                lastIndex = currentIndex;
            }

            n >>= 1;  // right shift (divide by 2)
            currentIndex++;
        }

        return maxGap;
    }
};