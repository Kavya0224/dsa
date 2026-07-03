class Solution {
public:
    vector<int> par;
    vector<int> Rank;

    Solution() {
        par.resize(26);
        Rank.resize(26, 0);
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (Rank[u] > Rank[v])
            par[v] = u;
        else if (Rank[u] < Rank[v])
            par[u] = v;
        else {
            par[v] = u;
            Rank[u]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        for (int i = 0; i < 26; i++)
            par[i] = i;

        for (auto &eq : equations) {
            if (eq[1] == '=') {
                unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0] - 'a') == find(eq[3] - 'a'))
                    return false;
            }
        }

        return true;
    }
};