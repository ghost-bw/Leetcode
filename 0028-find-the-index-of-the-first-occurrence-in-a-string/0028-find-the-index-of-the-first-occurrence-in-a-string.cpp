class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        int start = 0; // Possible starting index
        int i = 0;     // Current index in haystack
        int j = 0;     // Current index in needle

        while (i < n) {

            // Characters match
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                // Complete needle matched
                if (j == m) {
                    return start;
                }
            }

            // Characters do not match
            else {
                start++;

                i = start;

                j = 0;
            }
        }

        return -1;
    }
};