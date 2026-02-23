class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> candies(n, 1); // everyone gets at least 1

        // left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        long long sum = 0;
        for (int x : candies) sum += x;
        return (int)sum;
    }
};