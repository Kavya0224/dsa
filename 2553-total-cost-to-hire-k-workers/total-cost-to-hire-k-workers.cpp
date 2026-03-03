class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cands) {
        using P = pair<int,int>; // {cost, index}
        priority_queue<P, vector<P>, greater<P>> pq;

        int n = (int)costs.size();
        int l = 0, r = n - 1;

        // push up to cands from left
        for (int i = 0; i < cands && l <= r; i++) {
            pq.push({costs[l], l});
            l++;
        }
        // push up to cands from right
        for (int i = 0; i < cands && l <= r; i++) {
            pq.push({costs[r], r});
            r--;
        }

        long long ans = 0;

        while (k--) {
            auto [cost, idx] = pq.top();
            pq.pop();
            ans += cost;

            // refill from the same side the worker came from
            if (l <= r) {
                if (idx < l) { // came from left group
                    pq.push({costs[l], l});
                    l++;
                } else {        // came from right group
                    pq.push({costs[r], r});
                    r--;
                }
            }
        }

        return ans;
    }
};