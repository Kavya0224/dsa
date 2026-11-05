class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0;
        for(int i=0;i<arr1.size();i++){
            int f=1;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    f=0;
                    break;
                }
            }
            if(f==1) ct++;
        }
        return ct;
    }
};