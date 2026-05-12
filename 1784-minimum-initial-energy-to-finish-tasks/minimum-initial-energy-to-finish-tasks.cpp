class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int mn = 0;
        int curr = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (curr < minimum) {
                mn += (minimum - curr);
                curr = minimum;
            }

            curr -= actual;
        }

        return mn;
    }
};