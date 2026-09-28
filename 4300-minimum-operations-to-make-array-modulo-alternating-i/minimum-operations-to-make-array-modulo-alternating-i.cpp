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

        // Find the top 2 minimum cost target remainders for even positions
        int e1 = -1, e2 = -1;
        for (int x = 0; x < k; x++) {
            if (e1 == -1 || cost_even[x] < cost_even[e1]) {
                e2 = e1;
                e1 = x;
            } else if (e2 == -1 || cost_even[x] < cost_even[e2]) {
                e2 = x;
            }
        }

        // Find the top 2 minimum cost target remainders for odd positions
        int o1 = -1, o2 = -1;
        for (int y = 0; y < k; y++) {
            if (o1 == -1 || cost_odd[y] < cost_odd[o1]) {
                o2 = o1;
                o1 = y;
            } else if (o2 == -1 || cost_odd[y] < cost_odd[o2]) {
                o2 = y;
            }
        }

        // Pick the optimal combination where remainder targets are distinct
        if (e1 != o1) {
            return cost_even[e1] + cost_odd[o1];
        }

        ll ans = LLONG_MAX;
        if (o2 != -1) ans = min(ans, cost_even[e1] + cost_odd[o2]);
        if (e2 != -1) ans = min(ans, cost_even[e2] + cost_odd[o1]);

        return ans;
    }
};