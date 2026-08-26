class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        queue<int> q;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') q.push(i);
            if(q.size()==k){
                int st=q.front();
                q.pop();
                int len=i-st+1;
                string temp=s.substr(st,len);
                if(ans=="") ans=temp;
                else if(len<ans.size()) ans=temp;
                else if(ans.size()==len && temp<ans) ans=temp;
            }
        }
        return ans;
    }
};