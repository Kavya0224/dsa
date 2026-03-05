class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<magazine.size();i++) m1[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++) m2[ransomNote[i]]++;
        for(auto it:m2){
            if(m2[it.first]<=m1[it.first]) continue;
            else return false;
        }
        return true;
    }
};