class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> freq;
        for (char ch: jewels){
            freq[ch]=1;
        }
        int count=0;
        for(char ch:stones){
            if(freq[ch]==1)count++;
        }
        return count;
    }
};