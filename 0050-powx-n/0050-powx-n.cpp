class Solution {
public:
    double power(double x, int n){
        if(n==0) return 1.0;
        double half=power(x,n/2);
        if(n%2==0){
            return half*half;
        }else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        long long exp=n;
        if(n<0) return power(1/x,-exp);
        return power(x,exp);
    }
};
