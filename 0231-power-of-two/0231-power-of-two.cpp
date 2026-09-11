class Solution {
public:
    bool isPowerOfTwo(int n) {
    //   int ex=1;
    //   int n=m;
    //   if(n<=0) return false;
    //   while(n>1){
    //     ex*=2;
    //     n=n/2;
    //   }
    //   return (ex==m)?true:false;
    if(n<=0)return false;
    return !(n&(n-1));

    }
};