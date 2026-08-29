class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; i++) {
            paired[i] = {nums[i], i};
        }
        
        sort(paired.begin(), paired.end());
        
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && paired[j].first - paired[j - 1].first <= limit) {
                j++;
            }
            vector<int> indices;
            for (int k = i; k < j; k++) {
                indices.push_back(paired[k].second);
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = paired[i + k].first;
            }
            
            i = j;
        }
        
        return nums;
    }
};