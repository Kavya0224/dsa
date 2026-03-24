class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int strow = 0;               // Starting row index
        int stcol = 0;               // Starting column index
        int erow = n - 1;            // Ending row index
        int ecol = n - 1;    
        int ct=1;        // Ending column index
        vector<vector<int>> ans(n,vector<int>(n));             // Result vector to store spiral order

        // Loop until we traverse all layers
        while (strow <= erow && stcol <= ecol) {

            // Traverse top row from left to right
            for (int i = stcol; i <= ecol; i++) {
                ans[strow][i]=ct;
                ct++;
            }

            // Traverse rightmost column from top to bottom
            for (int i = strow + 1; i <= erow; i++) {
                ans[i][ecol]=ct;
                ct++;
            }

            // Traverse bottom row from right to left (only if multiple rows exist)
            for (int i = ecol - 1; i >= stcol; i--) {
                if (strow == erow) {
                    break; // Avoid double traversal of single row
                }
                ans[erow][i]=ct;
                ct++;
            }

            // Traverse leftmost column from bottom to top (only if multiple columns exist)
            for (int i = erow - 1; i >= strow + 1; i--) {
                if (stcol == ecol) {
                    break; // Avoid double traversal of single column
                }
                ans[i][stcol]=ct;
                ct++;
            }

            // Move towards the inner layer
            strow++;
            stcol++;
            erow--;
            ecol--;
        }

        return ans; // Return the spiral ordered list
    }
};