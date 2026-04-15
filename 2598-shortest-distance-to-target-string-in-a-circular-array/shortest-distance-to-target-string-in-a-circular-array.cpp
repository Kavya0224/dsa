class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int t=n;
        int i=startIndex,j=startIndex;
        while(t--){
            if(words[i%n]==target) return (n-t-1);
            if(words[(j+n)%n]==target) return n-t-1;
            i++; j--;
        }
        return -1;
    }
};