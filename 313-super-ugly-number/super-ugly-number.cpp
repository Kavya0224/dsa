class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int numPrimes = primes.size();
        vector<int> primeIndices(numPrimes, 0);
        vector<int> superUgly(n);
        superUgly[0] = 1;

        for (int i = 1; i < n; i++) {
            long long minVal = LLONG_MAX;

            for (int j = 0; j < numPrimes; j++) {
                minVal = min(minVal, 1LL * primes[j] * superUgly[primeIndices[j]]);
            }

            superUgly[i] = (int)minVal;

            for (int j = 0; j < numPrimes; j++) {
                if (minVal == 1LL * primes[j] * superUgly[primeIndices[j]]) {
                    primeIndices[j]++;
                }
            }
        }

        return superUgly[n - 1];
    }
};