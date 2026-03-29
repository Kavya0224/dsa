class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0) {
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] == 0 && nums[i + 1] == 0) return true;
            }
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2) return true;
            } else {
                mp[rem] = i;
            }
        }

        return false;
    }
};