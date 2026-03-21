class Solution {
public:
    int titleToNumber(string col) {
        long long ans = 0;
        long long ct = 1;
        
        for (int i = col.size() - 1; i >= 0; i--) {
            int rem = col[i] - 'A' + 1;
            ans += rem * ct;
            ct *= 26;
        }
        
        return ans;
    }
};