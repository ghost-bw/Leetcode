class Solution {
public:
    long long const mod=1000000007;
    int power(long long base,long long exp){
        long long result=1;
        base%=mod;
        while (exp > 0) {
            if (exp & 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long ec=(n+1)/2;
        long long oc=n/2;
        long long evenways=power(5,ec);
        long long oddways=power(4,oc);
        return (evenways*oddways)% mod;
    }
};