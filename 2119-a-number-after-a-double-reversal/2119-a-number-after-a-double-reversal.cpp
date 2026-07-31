class Solution {
public:
    bool isSameAfterReversals(int num) {
        int revnum=0;
        int num2=num;
        while(num2>0){
            int digit=num2%10;
            revnum=revnum*10+digit;
            num2/=10;
        }
        int check=0;
        while(revnum>0){
            int digit=revnum%10;
            check=check*10+digit;
            revnum/=10;
        }
        return (check==num)? true:false;
    }
};