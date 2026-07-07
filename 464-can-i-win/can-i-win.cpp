class Solution {
public:
    char memo[1 << 21]; 

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        
        memset(memo, 0, sizeof(memo));
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

private:
    bool dfs(int maxChoosableInteger, int total, int state) {
        if (memo[state] != 0) {
            return memo[state] == 1;
        }
        for (int i = 1; i <= maxChoosableInteger; i++) {
            int mask = 1 << i;
            
            if ((state & mask) == 0) {
                if (i >= total) {
                    memo[state] = 1;
                    return true;
                }
                if (!dfs(maxChoosableInteger, total - i, state | mask)) {
                    memo[state] = 1;
                    return true;
                }
            }
        }
        memo[state] = 2;
        return false;
    }
};