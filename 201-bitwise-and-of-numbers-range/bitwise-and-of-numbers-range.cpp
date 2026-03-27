class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left < right) {
            if(left==0) break;
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};