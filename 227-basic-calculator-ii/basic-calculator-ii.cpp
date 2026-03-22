class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push_back(num);
                } 
                else if (op == '-') {
                    st.push_back(-num);
                } 
                else if (op == '*') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top * num);
                } 
                else if (op == '/') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int ans = 0;
        for (int x : st) ans += x;
        return ans;
    }
};