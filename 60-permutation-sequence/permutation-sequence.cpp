class Solution {
public:
    void permi(string &num, string & temp, string &current,vector<bool>& visited,int n, int& k ){
        if(current.size()==num.size()){
             k--;
            if(k==0){
                temp=current;
            }
                return ;
        }

       for(int i = 0; i < num.size(); i++){
            if(!visited[i]){
                visited[i]=true;
                 current.push_back(num[i]);
                // swap(num[i],num[index]);
                permi(num,temp,current,visited,n,k);
                if(k == 0) return;
                // swap(num[i],num[index]);// reset
                current.pop_back();
                visited[i] = false;
            }
       }
    }

    string getPermutation(int n, int k) {
        string num="";
        for(int i=1;i<=n;i++){
            num += to_string(i);

        }
        string temp="";
        string current="";
        vector<bool>visited(n,false);
        // int index=0;
        permi(num, temp,current,visited, n,k);
        return temp;
    }
};