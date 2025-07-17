class Solution {
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        int last = -1e9;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 1e9 && nums[i] != last) {
                last = nums[i];
                curr.push_back(nums[i]);
                nums[i] = 1e9;
                solve(nums, ans, curr);
                nums[i] = last;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, ans, curr);
        return ans;
    }
};