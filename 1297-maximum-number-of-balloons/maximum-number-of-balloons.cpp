class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(int i=0;i<text.size();i++) mp[text[i]]++;
        int ct=0;
        while(mp['b']>0 && mp['a']>0 && mp['l']>1 && mp['o']>1 && mp['n']>0){
            ct++;
            mp['b']-=1;
            mp['a']-=1;
            mp['l']-=2;
            mp['o']-=2;
            mp['n']-=1;
        }
        return ct;
    }
};