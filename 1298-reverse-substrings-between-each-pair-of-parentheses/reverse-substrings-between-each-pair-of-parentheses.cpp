class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')') st.push(string(1,s[i]));
            else{
                string temp="";
                 
                while(st.top()!="("){
                    string t=st.top();
                    reverse(t.begin(),t.end());
                    temp+=t;
                    st.pop();
                }
                st.pop();
                st.push(temp);
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};