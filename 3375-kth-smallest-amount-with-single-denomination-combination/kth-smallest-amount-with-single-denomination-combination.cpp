class Solution {
public:
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countMultiples(long long m, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > m) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bits % 2 == 1) {
                total += m / current_lcm;
            } else {
                total -= m / current_lcm;
            }
        }
        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int min_coin = *min_element(coins.begin(), coins.end());
        long long low = 1, high = 1LL * min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};