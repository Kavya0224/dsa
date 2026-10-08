class Solution {
public:
    string removeOuterParentheses(string s) {
        int ct=0;
        int a=0;
        int b=0;
        while(a<s.length()){
            if(s[a]=='('){
                ct++;
                a++;
            }
            else if(s[a]==')' && ct==1){
                s.erase(a,1);
                s.erase(b,1);
               
                b=a-1;
                
            }
            else{
                ct--;
                a++;
            }
        }
        return s;
    }
};