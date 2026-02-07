class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_set<string> st;
        unordered_set<string> ans;

        for(int r=0;r<s.size()-9;r++){
            string temp=s.substr(r,10);
            if(st.count(temp)){
                ans.insert(temp);
            }
            st.insert(temp);
           
        }
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};