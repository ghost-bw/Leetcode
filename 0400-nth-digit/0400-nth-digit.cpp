class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)return n;
        long long digits = 1;
        long long count = 9;
        long long start = 1;
        while(n>digits*count){
            n-=digits*count;
            digits++;
            count*=10;
            start*=10;
        }
        long long index = n - 1;
        long long number = start + index / digits;
        int digitIndex = index % digits;

        string s = to_string(number);

        return s[digitIndex] - '0';
    }
};