class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0;
        int vowel=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            if(s[r]=='a' ||s[r]=='e' ||s[r]=='i' ||s[r]=='o' ||s[r]=='u') vowel++;
            if(r-l+1==k){
                ans=max(ans,vowel);
                if(s[l]=='a' ||s[l]=='e' ||s[l]=='i' ||s[l]=='o' ||s[l]=='u') vowel--;
                l++;
            }
        }
        return ans;
    }
};