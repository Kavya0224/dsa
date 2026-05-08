class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<int> dist(n, -1);

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if(i == n - 1) return d;

            if(i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if(i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if(isPrime(val) && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for(int multiple = val; multiple <= mx; multiple += val) {
                    if(mp.count(multiple)) {
                        for(int idx : mp[multiple]) {
                            if(dist[idx] == -1) {
                                dist[idx] = d + 1;
                                q.push(idx);
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
};