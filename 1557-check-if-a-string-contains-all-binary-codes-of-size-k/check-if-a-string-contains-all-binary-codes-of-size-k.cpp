class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (int)s.size();
        if (n < k) return false;

        int need = 1 << k;
        unordered_set<string> st;
        st.reserve(min(n, need) * 2);

        for (int i = 0; i + k <= n; i++) {
            st.insert(s.substr(i, k));
            if (st.size() == need) return true; 
        }
        return st.size() == need;
    }
};