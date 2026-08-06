class Solution {
public:
    int smallestNumber(int n, int t) {
       
        int ans=0;

        while(!ans){
            int product=1;
            int p=n;
            while(p>0)
            {   int digit=p%10;
                product*=digit;
                p=p/10;
            }
            if(product%t==0){
                ans=n;
                break;
            }
            n++;
        }
        return ans;
    }
};