class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        const long long MAX_BOUND = 25200LL; 
        for (int i = 0; i < (int)nums.size(); i++) {
            long long lcm = nums[i];
            long long g = nums[i];
            long long prod = 1LL;
            for (int j = i; j < (int)nums.size(); j++) {
                g = gcd(g, nums[j]);
                lcm = (lcm / gcd(lcm, nums[j])) * nums[j];
                prod *= nums[j];

                if (prod > MAX_BOUND) break;

                if (prod == lcm * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};