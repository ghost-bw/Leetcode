class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.length();
        if(n==2 && (word[0]==word[1] || abs(word[0]-word[1])==1)) return 1;
        int count=0;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1] || abs(word[i]-word[i-1])==1){
                
                count++;
                i++;
            }
        }
        return count;
    }
};