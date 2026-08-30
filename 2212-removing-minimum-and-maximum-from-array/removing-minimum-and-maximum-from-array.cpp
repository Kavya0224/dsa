class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0], maxVal = nums[0];
        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        int front = maxIdx + 1;
        int back = n - minIdx;
        int both = (minIdx + 1) + (n - maxIdx);

        return min({front, back, both});
    }
};