class Solution {
public:
    int countCommas(int n) {
        int totalcommas = 0;
        int count = 0;
        int temp = n;

        while (temp != 0) {
            temp /= 10;
            count++;
        }

        if (count < 4) {
            totalcommas = 0;
        }
        else if (count < 7) {
            totalcommas = n - 999;
        }
        else {
            totalcommas = (n - 999) + (n - 999999);
        }

        return totalcommas; 
    }
};