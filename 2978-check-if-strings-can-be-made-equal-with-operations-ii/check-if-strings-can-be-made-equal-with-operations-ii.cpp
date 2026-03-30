class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n;i++){
            if(i%2==0) mp1[s1[i]]++;
            else mp2[s1[i]]++;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(mp1[s2[i]]==0) return false;
                mp1[s2[i]]--;
            }
            else{
                if(mp2[s2[i]]==0) return false;
                mp2[s2[i]]--;
            }
        }
        return true;
    }
};