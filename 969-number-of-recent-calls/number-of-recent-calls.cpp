#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
      queue<int> q;
public:
    // RecentCounter() { } // nothing to init explicitly
    int ping(int t) {
        q.push(t);
        while(!q.empty() && q.front() < t - 3000) q.pop();
        return (int)q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/*
Example usage:
RecentCounter rc;
rc.ping(1);    // returns 1
rc.ping(100);  // returns 2
rc.ping(3001); // returns 3
rc.ping(3002); // returns 3
*/