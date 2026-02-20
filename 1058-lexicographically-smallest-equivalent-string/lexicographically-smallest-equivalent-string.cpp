class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return;
        // attach larger root to smaller root so representative is smallest char
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;

        for (int i = 0; i < (int)s1.size(); i++) {
            unite(s1[i] - 'a', s2[i] - 'a', parent);
        }

        for (char &c : baseStr) {
            c = char('a' + find(c - 'a', parent));
        }
        return baseStr;
    }
};