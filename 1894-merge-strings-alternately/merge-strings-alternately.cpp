class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int turn=1;
        string ans;
        while(i<word1.size() && j<word2.size()){
            if(turn==1){
                turn=0;
                ans+=word1[i];
                i++;
            }
            else{
                turn=1;
                ans+=word2[j];
                j++;
            }
        }
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};