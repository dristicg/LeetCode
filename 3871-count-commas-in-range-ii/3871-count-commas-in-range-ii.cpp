class Solution {
public:
    long long countCommas(long long n) {
        long long totalcommas = 0;
        long long start = 1000;

        while (start <= n) {
            totalcommas += n - start + 1;
            start *= 1000;
        }

        return totalcommas;
    }
};