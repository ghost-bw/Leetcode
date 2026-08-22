class Solution {
public:
    bool checkDivisibility(int n) {
        int p=n;
        int sum=0;
        int product=1;
        int ans=0;
        while(p>0){
            int digit=p%10;
            p/=10;
            sum+=digit;
            product*=digit;
            ans=sum+product;
        }
        return (n%ans==0);
    }
};