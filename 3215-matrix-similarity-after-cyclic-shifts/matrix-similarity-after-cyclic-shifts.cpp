class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k %= m;

        vector<vector<int>> arr = mat;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                reverse(arr[i].begin(), arr[i].begin() + k);
                reverse(arr[i].begin() + k, arr[i].end());
                reverse(arr[i].begin(), arr[i].end());
            } else {
                reverse(arr[i].begin(), arr[i].end());
                reverse(arr[i].begin(), arr[i].begin() + k);
                reverse(arr[i].begin() + k, arr[i].end());
            }
        }

        return arr == mat;
    }
};