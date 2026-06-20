class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        for (int i = 1; i < m; i++) {
            int max_left = restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]);
            restrictions[i][1] = min(restrictions[i][1], max_left);
        }
        
        for (int i = m - 2; i >= 0; i--) {
            int max_right = restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]);
            restrictions[i][1] = min(restrictions[i][1], max_right);
        }
        
        int mx = 0;
        for (int i = 1; i < m; i++) {
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];
            int distance = restrictions[i][0] - restrictions[i - 1][0];
            
            int peak = (distance + h1 + h2) / 2;
            mx = max(mx, peak);
        }
        
        int last_idx = restrictions[m - 1][0];
        int last_h = restrictions[m - 1][1];
        mx = max(mx, last_h + (n - last_idx));
        
        return mx;
    }
};