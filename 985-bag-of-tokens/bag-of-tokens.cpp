class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j=tokens.size()-1;
        int mx=0;
        int score=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>=1){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
            mx=max(mx,score);
        }
        return mx;
    }
};