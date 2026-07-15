class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0,sumeven=0;
        for(int i=1;i<=n*2;i++){
            if(i%2==0){
                sumeven+=i;
            }else{
                sumodd+=i;
            }
        }
        if(sumodd>sumeven){
            int ans=sumodd%sumeven;
            if(ans==0){
                return sumeven;
            }
            if(sumodd%ans==0 && sumeven%ans==0){
                return ans;
            }
        }else{
            int ans=sumeven%sumodd;
            if(ans==0){
                return sumodd;
            }
            if(sumodd%ans==0 && sumeven%ans==0){
                return ans;
            }
        }
        return 1;
    }
};