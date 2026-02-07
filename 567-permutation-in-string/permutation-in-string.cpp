class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(int i=0;i<s1.size();i++) a1[s1[i]-'a']++;
        int l=0;
        int f=0;
        for(int i=0;i<s2.size();i++){
            a2[s2[i]-'a']++;
            if(i-l+1==s1.size()){
                for(int i=0;i<26;i++){
                    if(a1[i]!=a2[i]){
                        f=1;
                        break;
                    }
                    
                }
                if(f==0) return true;
                f=0;
                a2[s2[l]-'a']--;
                l++;
            }
        }
        return false;
    }
};