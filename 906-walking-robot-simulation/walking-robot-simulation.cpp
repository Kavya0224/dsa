class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,vector<int>>  mp,m;
        for(int i=0;i<obstacles.size();i++){
            mp[obstacles[i][0]].push_back(obstacles[i][1]);
        }
        for(int i=0;i<obstacles.size();i++){
            m[obstacles[i][1]].push_back(obstacles[i][0]);
        }
        int a=0,b=0;
        vector<int> d={1,2,-1,-2};
        int dir=0;
        int mx=0;
        for(int i:commands){
            if(i==-1){
                dir=(dir+1)%4;
            }
            else if(i==-2) dir=(4+dir-1)%4;
            else{
                if(d[dir]==1){
                    while(i--){
                        if(m.find(a+1)==m.end()) a++;
                        else{
                            int f=0;
                            for(auto it:m[a+1]){
                                if(it==b){
                                    f=1;
                                    break;
                                }
                            }
                            if(f==0) a++;
                            else break;
                        }
                        int temp=(a*a)+(b*b);
                        mx=max(mx,temp);
                    }
                }
                else if(d[dir]==2){
                    while(i--){
                        if(mp.find(b+1)==mp.end()) b++;
                        else{
                            int f=0;
                            for(auto it:mp[b+1]){
                                if(it==a){
                                    f=1;
                                    break;
                                }
                            }
                            if(f==0) b++;
                            else break;

                        }
                        int temp=(a*a)+(b*b);
                        mx=max(mx,temp);
                    }
                }
                if(d[dir]==-1){
                    while(i--){
                        if(m.find(a-1)==m.end()) a--;
                        else{
                            int f=0;
                            for(auto it:m[a-1]){
                                if(it==b){
                                    f=1;
                                    break;
                                }
                            }
                            if(f==0) a--;
                            else break;
                        }
                        int temp=(a*a)+(b*b);
                        mx=max(mx,temp);
                    }
                }
                else if(d[dir]==-2){
                    while(i--){
                        if(mp.find(b-1)==mp.end()) b--;
                        else{
                            int f=0;
                            for(auto it:mp[b-1]){
                                if(it==a){
                                    f=1;
                                    break;
                                }
                            }
                            if(f==0) b--;
                            else break;
                        }
                    }
                    int temp=(a*a)+(b*b);
                        mx=max(mx,temp);
                }
            }
        }
        
        return mx;
    }
};