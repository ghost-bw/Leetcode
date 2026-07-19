class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> st;
        for(string &word: words){
            string code = "";
            for (char ch : word) {
                code += morse[ch - 'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};