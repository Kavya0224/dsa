class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        int f=0;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target && f==0){
                ans=letters[i];
                f=1;
            }
            if(letters[i]>target && letters[i]<ans){
                ans=letters[i];
            }
        }
        if(f) return ans;
        return letters[0];
    }
};