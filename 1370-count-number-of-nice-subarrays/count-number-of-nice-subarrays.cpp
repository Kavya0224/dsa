class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int odd = 0;
        int ans = 0;
        int cnt = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 == 1) {
                odd++;
                cnt = 0;  // reset count when a new odd appears
            }

            while (odd == k) {
                cnt++;
                if (nums[l] % 2 == 1) odd--;
                l++;
            }

            ans += cnt;
            r++;
        }
        return ans;
    }
};
