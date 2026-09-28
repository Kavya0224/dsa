class Solution {
public:
    using ll = long long;

    ll calc(const vector<int>& freq, int target_rem, int k) {
        ll cost = 0;
        for (int r = 0; r < k; r++) {
            if (freq[r] == 0) continue;
            int d = abs(r - target_rem);
            int min_dist = min(d, k - d);
            cost += (ll)freq[r] * min_dist;
        }
        return cost;
    }

    int minOperations(vector<int>& nums, int k) {
        vector<int> even_freq(101, 0);
        vector<int> odd_freq(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            int rem = (nums[i] % k + k) % k;
            if (i % 2 == 0) {
                even_freq[rem]++;
            } else {
                odd_freq[rem]++;
            }
        }

        vector<ll> cost_even(k, 0), cost_odd(k, 0);
        for (int x = 0; x < k; x++) {
            cost_even[x] = calc(even_freq, x, k);
            cost_odd[x] = calc(odd_freq, x, k);
        }

        ll min_total_cost = LLONG_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x != y) {
                    min_total_cost = min(min_total_cost, cost_even[x] + cost_odd[y]);
                }
            }
        }

        return min_total_cost;
    }
};