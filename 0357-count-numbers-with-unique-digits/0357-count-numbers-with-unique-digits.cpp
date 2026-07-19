class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int o=9;
        int p=10;
        for(int i=1;i<n;i++){
            o=o*(10-i);
            p=o+p;
        }
        return p;
    }
};