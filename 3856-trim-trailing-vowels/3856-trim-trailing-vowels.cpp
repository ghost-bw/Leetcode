class Solution {
public:
    bool isvowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string trimTrailingVowels(string s) {
        int n=s.length();
        int i=n-1;
        while(i>=0 && isvowel(s[i])) {
            i--;
        }

        if(i<0)return"";
        if(i==n-1)return s;
        return s.substr(0,i+1);
    }
};