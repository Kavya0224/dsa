class Solution {
public:
    int longestPalindrome(string s) {
        int even=0,odd=0;
        int ans=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(auto it:mp){
            if(it.second%2==1) odd++;
            ans+=2*(it.second/2);
        }
        if(odd) return ans+1;
        return ans;
    }
};