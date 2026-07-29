
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int q=0,p=0;
            while(q<queries[i].size()){
                if(p<pattern.size() && queries[i][q]==pattern[p]){
                    p++;
                }
                else if(queries[i][q]>='A' && queries[i][q]<='Z'){
                    break;
                }
                q++;
            }
            if(q==queries[i].size() && p==pattern.size()) ans[i]=true;
        }
        return ans;
    }
};