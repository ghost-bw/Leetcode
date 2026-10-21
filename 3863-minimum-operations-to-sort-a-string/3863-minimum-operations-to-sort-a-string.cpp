class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(begin(s),end(s)))return 0;
        if(n==2)return -1;
        char min_ch=*min_element(begin(s),end(s));
        char max_ch=*max_element(begin(s),end(s));
        if(s[0]==min_ch || s[n-1]==max_ch)return 1;
        char min_mid=*min_element(begin(s)+1,end(s)-1);
        char max_mid=*max_element(begin(s)+1,end(s)-1);
        if(s[0]>max_mid&& s[n-1]<min_mid)return 3;
        return 2;
    }
};