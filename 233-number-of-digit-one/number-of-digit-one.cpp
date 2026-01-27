class Solution {
public:
    long long solve(long long n, long long factor) {
        if (n / factor == 0) return 0;

        long long lower = n % factor;
        long long curr = (n / factor) % 10;
        long long higher = n / (factor * 10);

        long long ans = 0;

        if (curr == 0)
            ans = higher * factor;
        else if (curr == 1)
            ans = higher * factor + lower + 1;
        else
            ans = (higher + 1) * factor;

        return ans + solve(n, factor * 10);
    }

    int countDigitOne(int n) {
        return solve(n, 1);
    }
};
