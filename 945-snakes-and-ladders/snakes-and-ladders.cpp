class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getPos = [&](int square) -> pair<int, int> {
            int r = (square - 1) / n;
            int c = (square - 1) % n;
            int row = n - 1 - r;
            int col = (r % 2 == 0) ? c : (n - 1 - c);
            return {row, col};
        };

        vector<int> dist(n * n + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n * n) return dist[curr];

            for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                auto [r, c] = getPos(next);
                int destination = (board[r][c] != -1) ? board[r][c] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }

        return -1;
    }
};