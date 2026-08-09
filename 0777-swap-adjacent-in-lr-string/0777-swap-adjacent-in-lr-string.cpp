class Solution {
public:
    bool canTransform(string start, string result) {
        // 1. Validate relative order first
        string s1 = "", s2 = "";
        for (char c : start) if (c != 'X') s1 += c;
        for (char c : result) if (c != 'X') s2 += c;
        if (s1 != s2) return false;
        
        int n = start.length();
        int i = 0, j = 0;
        
        // 2. Loop until either pointer finishes traversing
        while (i < n && j < n) {
            // Find next non-X char in start (bound protected by i < n)
            while (i < n && start[i] == 'X') i++;
            // Find next non-X char in result (bound protected by j < n)
            while (j < n && result[j] == 'X') j++;
            
            // If one or both reach the end, verify they both completed
            if (i == n || j == n) {
                return i == j;
            }
            
            // L can only move left, so its start index must be >= result index
            if (start[i] == 'L' && i < j) return false;
            // R can only move right, so its start index must be <= result index
            if (start[i] == 'R' && i > j) return false;
            
            i++;
            j++;
        }
        
        return true;
    }
};
