#include <vector>
#include <algorithm>

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;

        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        long long non_intersecting = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && starts[i] > ends[j]) {
                j++;
            }
            non_intersecting += (i - j);
        }

        return non_intersecting;
    }
};