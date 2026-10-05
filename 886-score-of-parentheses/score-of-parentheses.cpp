class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')') st.push(string(1, s[i]));
            else{
                int temp=0;
                while(st.top()!="("){
                    temp+=stoi(st.top());
                    st.pop();
                }
                st.pop();
                if(temp>0) temp*=2;
                else temp=1;
                st.push(to_string(temp));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans;
    }
};