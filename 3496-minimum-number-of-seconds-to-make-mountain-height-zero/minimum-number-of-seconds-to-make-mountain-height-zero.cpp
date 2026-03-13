class Solution {
public:
    unsigned long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        int n=workerTimes.size();
        priority_queue<pair<unsigned long long,pair<int,int>>,vector<pair<unsigned long long,pair<int,int>>>,greater<pair<unsigned long long,pair<int,int>>>> pq;
        
        for(int i=0;i<n;i++){
                pq.push({workerTimes[i],{i,1}});
            }
           
        unsigned long long ans=0,res=0;
        while(!pq.empty()){
            unsigned long long time=pq.top().first;
            int i=pq.top().second.first;
            long long mul=pq.top().second.second;
            pq.pop();
            res++;
           
            ans=max(ans,time);
            if(res==mountainHeight){
                break;
            }
            unsigned long long t=time+workerTimes[i]*(mul+1);
            pq.push({t,{i,mul+1}});
        }
        // unsigned long long ct=0;
        // for(int i=0;i<ans;i++) ct+=workerTimes[idx]*(i+1);
        return ans;

    }
};