class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        string temp=s.substr(0,k);
        int ct=0;
        for(int i=k-1;i<s.size();i++){
            if(i==k-1) ;
            else{
                temp.erase(0,1);
                temp+=s[i];
            } 
            int n=stoi(temp);
            cout<<n<<" ";
            if(n>0 && num%n==0) ct++;
            
        }
        return ct;
    }
};