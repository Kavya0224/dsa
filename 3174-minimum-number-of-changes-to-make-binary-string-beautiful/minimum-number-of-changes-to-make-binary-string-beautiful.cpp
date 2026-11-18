class Solution {
public:
    int minChanges(string s) {
        int turn;
        int ct=0;
        if(s[0]=='1') turn=1;
        else turn=0;
        for(int i=0;i<s.size();i++){
            int st=i;
            cout<<st<<" ";
            while(i<s.size() && (s[i]-'0')==turn) i++;
            int sz=i-st;
            i--;
            if(sz%2==1){
                ct++;
                int temp=1-turn;
                s[i]=(char)(temp+'0');
                i--;
            }
            turn=1-turn;
        }
        return ct;
    }
};