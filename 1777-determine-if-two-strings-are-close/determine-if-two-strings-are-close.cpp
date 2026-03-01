class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        if(m!=n) return false;
        for(int i=0;i<n;i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        for(auto it:m2){
            if(m1.find(it.first)==m1.end()) return false;
        }
        for(auto it:m1){
            if(m2.find(it.first)==m2.end()) return false;
        }
        unordered_map<int,int> f1;
        unordered_map<int,int> f2;
        for(auto it:m1) f1[it.second]++;
        for(auto it:m2) f2[it.second]++;
        for(auto it:m1){
            if(f1[it.second]!=f2[it.second]) return false;
        }
        return true;
    }
};