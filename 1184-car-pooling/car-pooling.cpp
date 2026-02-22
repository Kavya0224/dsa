class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0); // stops are in [0..1000]

        for (auto &t : trips) {
            int pass = t[0];
            int start = t[1];
            int end = t[2];
            diff[start] += pass;
            diff[end] -= pass;
        }

        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if (curr > capacity) return false;
        }
        return true;
    }
};