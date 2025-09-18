class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;  // base case for prefix sum equal to k
    int count = 0, sum = 0;

    for (int num : nums) {
        sum += num;

        // check if there is a prefix sum that leads to sum - k
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }

        // store current prefix sum in the map
        prefixSumCount[sum]++;
    }

    return count;
    }
};