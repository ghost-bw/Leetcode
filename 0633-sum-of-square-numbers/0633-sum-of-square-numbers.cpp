class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        long long j=sqrt(c);
        while(i<=j){
            long long sq=i*i+j*j;
            if(sq==c)return true;
            else if(sq>c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};