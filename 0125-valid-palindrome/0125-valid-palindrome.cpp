class Solution {
public:
    string cleanlower(string str){
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    str.erase(
        remove_if(str.begin(), str.end(), [](unsigned char c) {
            return !isalnum(c);
        }), 
        str.end()
    );

    return str;
    }
    bool isPalindrome(string s) {
        string newS=cleanlower(s);
        int l=0;
        int r=newS.length()-1;
        while(l<r){
            if(newS[l++]!=newS[r--])return false;
            
        }
        return true;
    }
};