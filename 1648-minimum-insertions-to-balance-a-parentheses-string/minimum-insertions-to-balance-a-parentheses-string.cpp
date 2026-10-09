class Solution {
public:
    int minInsertions(string s) {
        int ct=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.empty() || st.top()=='(') st.push(s[i]);
                else{
                    cout<<i<<" ";
                    ct++;
                    st.pop();
                    st.pop();
                    st.push('(');
                }
            }
            else{
                if(st.empty()){   
                    cout<<i<<" ";
                    ct++;
                    st.push('(');
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.push(')');
                }
                else{
                    st.pop();
                    st.pop();
                }
            }
            
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            if(st.top()==')'){
                st.pop();
                ct--;
            }
            ct+=2;
            st.pop();
        }
        return ct;
    }
};