class Solution {
    map<vector<int>, int> memo;

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (memo.count(needs)) {
            return memo[needs];
        }
        int res = 0;
        for (int i = 0; i < needs.size(); ++i) {
            res += needs[i] * price[i];
        }

        for (const auto& offer : special) {
            vector<int> next_needs = needs;
            bool valid = true;
            for (int i = 0; i < needs.size(); ++i) {
                if (offer[i] > needs[i]) {
                    valid = false;
                    break;
                }
                next_needs[i] -= offer[i];
            }
            if (valid) {
                res = min(res, offer.back() + shoppingOffers(price, special, next_needs));
            }
        }

        return memo[needs] = res;
    }
};