class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(26, 0);
        vector<int> first(26, -1);

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u';
        };

        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                freq[s[i] - 'a']++;

                if(first[s[i] - 'a'] == -1)
                    first[s[i] - 'a'] = i;
            }
        }

        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            int fa = freq[a - 'a'];
            int fb = freq[b - 'a'];

            if(fa != fb)
                return fa > fb;

            return first[a - 'a'] < first[b - 'a'];
        });

        int ptr = 0;

        for(int i = 0; i < s.size(); i++) {
            if(!isVowel(s[i]))
                continue;

            while(ptr < 5 && freq[vowels[ptr] - 'a'] == 0)
                ptr++;

            s[i] = vowels[ptr];
            freq[vowels[ptr] - 'a']--;
        }

        return s;
    }
};