class Solution {
public:
    string convertToTitle(int col) {
        string ans = "";
        
        while (col > 0) {
            col--;  // 🔥 key step
            ans += char('A' + (col % 26));
            col /= 26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};