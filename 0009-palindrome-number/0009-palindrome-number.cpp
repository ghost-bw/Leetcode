class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int p=x;
        long long revsum=0;
        
        while(p>0){
            int digit=p%10;
            p=p/10;
            revsum=revsum*10+digit;
          
        }
        if(revsum==x){
            return true;
        }
        return false;
    }
};