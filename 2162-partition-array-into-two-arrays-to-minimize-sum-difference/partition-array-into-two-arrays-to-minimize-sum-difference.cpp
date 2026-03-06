class Solution {
public:
    void generate(vector<int>& arr, vector<vector<int>>& res) {
        int n = arr.size();
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                    cnt++;
                }
            }
            res[cnt].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int totalSum = 0;
        for (int x : nums) totalSum += x;

        vector<vector<int>> leftSums(n + 1), rightSums(n + 1);

        generate(left, leftSums);
        generate(right, rightSums);

        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : leftSums[k]) {
                int need = n - k;

                int target = totalSum / 2 - s1;

                auto& vec = rightSums[need];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int subsetSum = s1 + *it;
                    ans = min(ans, abs(totalSum - 2 * subsetSum));
                }

                if (it != vec.begin()) {
                    --it;
                    int subsetSum = s1 + *it;
                    ans = min(ans, abs(totalSum - 2 * subsetSum));
                }
            }
        }

        return ans;
    }
};