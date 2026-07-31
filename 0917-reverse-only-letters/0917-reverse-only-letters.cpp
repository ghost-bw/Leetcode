class Solution {
public:
    bool isAlphabet(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    string reverseOnlyLetters(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(!isAlphabet(s[left])){
                left++;
                continue;
            }
            if(!isAlphabet(s[right])){
                right--;
                continue;
            }
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};