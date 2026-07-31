class Solution {
public:
    bool isAlpha(char s){
        return (s>='a' && s<='z');
    }
    string reverseByType(string s) {
        int left=0;
        int n=s.length();
        int right=n-1;
        while(left<right){
            if(!isAlpha(s[left])){left++; continue;}
            if(!isAlpha(s[right])){right--; continue;}
            swap(s[left],s[right]);
            left++;
            right--;
        }
        left=0;
        right=n-1;
        while(left<right){
            if(isAlpha(s[left])){left++; continue;}
            if(isAlpha(s[right])){right--; continue;}
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};