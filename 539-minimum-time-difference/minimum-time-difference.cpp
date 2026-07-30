class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        if (n > 1440) return 0;

        sort(arr.begin(), arr.end());
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int hr = stoi(arr[i+1].substr(0,2)) - stoi(arr[i].substr(0,2));
            int a = stoi(arr[i].substr(3,2));
            int b = stoi(arr[i+1].substr(3,2));
            if (b >= a) ans = min(ans, hr * 60 + b - a);
            else {
                hr--;
                ans = min(ans, hr * 60 + 60 - a + b);
            }
        }

        int hr = stoi(arr[n-1].substr(0,2));
        int mint = stoi(arr[n-1].substr(3,2));
        int h_first = stoi(arr[0].substr(0,2));
        int m_first = stoi(arr[0].substr(3,2));

        int last_mins = hr * 60 + mint;
        int first_mins = h_first * 60 + m_first;

        ans = min(ans, (1440 - last_mins) + first_mins);

        return ans;
    }
};