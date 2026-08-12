class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
        ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int c1=0;
        for(int i=0;i<n/2;i++){
            if(isVowel(s[i]))c1++;
        }
        for(int i=n/2;i<n;i++){
            if(isVowel(s[i]))c1--;
        }
        return (c1==0);
    }
};