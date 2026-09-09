class Solution {
public:
    int findComplement(int num) {
        long long all_ones=num;
        while ((all_ones & (all_ones + 1)) != 0) {
            all_ones |= (all_ones >> 1);
        }
        return num^all_ones;
    }
};