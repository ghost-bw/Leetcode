class Solution {
public:
    bool isPowerOfTwo(int m) {
      int ex=1;
      int n=m;
      while(n>1){
        ex*=2;
        n=n/2;
      }
      return (ex==m)?true:false;

    }
};