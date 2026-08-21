class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
    string reverseVowels(string s) {
        int low=0;
        int high=s.length()-1;
        while(low<high){
            while(!isVowel(s[low]) && low<high){
                low++;
            }
            while(!isVowel(s[high]) && low<high){
                high--;
            }
            swap(s[low],s[high]);
            low++;
            high--;
        }
        return s;
    }
};