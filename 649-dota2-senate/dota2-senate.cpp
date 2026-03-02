class Solution {
public:
    string predictPartyVictory(string s) {
        string temp="";
        queue<char> q;
        int i=0;
        int round=10;
        int n=s.size();
        while(round--){
            while(true){
                if(i==s.size()){
                s=temp;
                temp="";
                i=0;
                break;
            }
            if(!q.empty() && q.front()==s[i]){
                q.pop();
                i++;
                continue;
            }
            if(s[i]=='R'){
                q.push('D');
                temp+='R';
            }
            else{
                q.push('R');
                temp+='D';
            }
            i++;
            }
        }
        if(s[0]=='R') return "Radiant";
        else return "Dire";
    }
};