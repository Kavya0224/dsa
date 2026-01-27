class Solution {
public:
    string res;
    bool found = false;

    void helper(vector<int>& nums, vector<bool>& used, int k, string& path, int& ct) {
        if (found) return;
        if (path.size() == nums.size()) {
            ct++;
            if (ct == k) {
                res = path;
                found = true;
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path += to_string(nums[i]);
            helper(nums, used, k, path, ct);
            path.pop_back();
            used[i] = false;
        }
    }

    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        vector<bool> used(n, false);
        string path = "";
        int ct = 0;
        helper(nums, used, k, path, ct);
        return res;
    }
};
