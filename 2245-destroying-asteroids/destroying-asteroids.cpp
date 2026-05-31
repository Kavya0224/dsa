class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        unsigned long long temp=1LL*mass;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]>temp) return false;
            else{
                temp+=1LL*arr[i];
            }
        }
        return true;
    }
};