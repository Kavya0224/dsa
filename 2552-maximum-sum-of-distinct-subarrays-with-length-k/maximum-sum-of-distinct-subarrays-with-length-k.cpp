class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long sum = 0, ans = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            // remove duplicates
            while (s.count(nums[r])) {
                s.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            s.insert(nums[r]);
            sum += nums[r];

            // keep window size <= k
            if (r - l + 1 > k) {
                s.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            // valid window
            if (r - l + 1 == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
