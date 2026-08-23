class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) return false;
        
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            string w = words[i];
            
            // Check character to word mapping
            if (charToWord.count(ch) && charToWord[ch] != w) return false;
            
            // Check word to character mapping (Prevents multiple chars mapping to same word)
            if (wordToChar.count(w) && wordToChar[w] != ch) return false;
            
            // Establish the two-way relationship
            charToWord[ch] = w;
            wordToChar[w] = ch;
        }
        
        return true;
    }
};
