class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s1.size();i++){
            if(i%2==0) m1[s1[i]]++;
            else m2[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            if(i%2==0){
                if(m1[s2[i]]==0) return false;
                m1[s2[i]]--;
            }
            else{
                if(m2[s2[i]]==0) return false;
                m2[s2[i]]--;
            }
        }
        return true;
    }
};