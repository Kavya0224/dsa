class Solution {
public:
    int findComplement(int num) {
        int bits = 32 - __builtin_clz(num);
        unsigned int x = (1u << bits) - 1;
        return num ^ x;
    }
};