class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(target.begin(), target.end());
        mt19937_64 rng(1337);
        unordered_map<int, unsigned long long> val_to_hash;
        for (int x : nums) {
            if (val_to_hash.find(x) == val_to_hash.end()) {
                val_to_hash[x] = rng();
            }
        }

        // 2. Precompute prefix sums for hashes and dips
        vector<unsigned long long> pref_h_nums(n + 1, 0), pref_h_target(n + 1, 0);
        vector<int> pref_dips(n, 0); // Internal dips: nums[i] > nums[i+1]

        for (int i = 0; i < n; ++i) {
            pref_h_nums[i + 1] = pref_h_nums[i] + val_to_hash[nums[i]];
            pref_h_target[i + 1] = pref_h_target[i] + val_to_hash[target[i]];
            if (i < n - 1) {
                pref_dips[i + 1] = pref_dips[i] + (nums[i] > nums[i + 1] ? 1 : 0);
            }
        }

        long long total_k_sum = 0;

        // 3. Iterate through all divisors k of n
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool possible = true;
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Condition A: Multisets must match
                unsigned long long hash_n = pref_h_nums[end + 1] - pref_h_nums[start];
                unsigned long long hash_t = pref_h_target[end + 1] - pref_h_target[start];
                if (hash_n != hash_t) {
                    possible = false;
                    break;
                }

                // Condition B: Must be a cyclic rotation (at most 1 dip)
                // Internal dips in [start, end]
                int dips = pref_dips[end] - pref_dips[start];
                // Wrap-around dip from end to start
                if (nums[end] > nums[start]) {
                    dips++;
                }

                if (dips > 1) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                total_k_sum += k;
            }
        }

        return total_k_sum;
    }
};