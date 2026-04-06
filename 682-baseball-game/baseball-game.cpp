class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans=0;
        for(auto c:operations){
            if(c=="C"){
                if(!st.empty()) st.pop();
            }
            else if(c=="D"){
                if(!st.empty()) st.push(2*st.top());
            }
            else if(c=="+"){
                if(st.size()>=2){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.push(a);
                    st.push(a+b);
                }
            }
            else st.push(stoi(c));
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};