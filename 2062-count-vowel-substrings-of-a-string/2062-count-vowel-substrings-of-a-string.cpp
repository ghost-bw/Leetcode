class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int countVowelSubstrings(string word) {
        int last[5] = {-1, -1, -1, -1, -1};
        int start = 0;
        int ans = 0;

        for (int r = 0; r < word.size(); r++) {

            // Consonant: valid substring must start after it
            if (!isVowel(word[r])) {
                start = r + 1;
                last[0] = last[1] = last[2] = last[3] = last[4] = -1;
                continue;
            }

            int idx;

            if (word[r] == 'a') idx = 0;
            else if (word[r] == 'e') idx = 1;
            else if (word[r] == 'i') idx = 2;
            else if (word[r] == 'o') idx = 3;
            else idx = 4;

            last[idx] = r;

            // All 5 vowels must have appeared
            if (last[0] != -1 && last[1] != -1 &&
                last[2] != -1 && last[3] != -1 &&
                last[4] != -1) {

                int earliest = min({last[0], last[1], last[2],
                                    last[3], last[4]});

                ans += earliest - start + 1;
            }
        }

        return ans;
    }
};