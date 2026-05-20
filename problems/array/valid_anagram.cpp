class Solution {
public:
    /* =======================================================
       1. BRUTE FORCE (Sorting)
       Time: O(N log N) | Space: O(1)
       Idea: Sort both strings. If they match, they are anagrams.
       ======================================================= */
    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }

    /* =======================================================
       2. BETTER (Hash Map)
       Time: O(N) | Space: O(K) where K is unique characters
       Idea: Count characters using map. Good for Unicode/any char.
       ======================================================= */
    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     unordered_map<char, int> count;
    //     for (char c : s) count[c]++;
    //     for (char c : t) {
    //         if (--count[c] < 0) return false;
    //     }
    //     return true;
    // }

    /* =======================================================
       3. BEST (Optimized Frequency Array)
       Time: O(N) | Space: O(1) (Fixed size 26)
       Idea: One loop to count up, one loop to count down + early exit.
       ======================================================= */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        // Using a fixed raw array is faster than std::vector 
        // because it avoids heap allocation memory overhead.
        int ccount[26] = {0};
        
        // Count frequencies of characters in string s
        for (char c : s) {
            ccount[c - 'a']++;
        }
        
        // Decrement counts using string t. 
        // If a count goes below 0, t has more of this char than s.
        for (char c : t) {
            if (--ccount[c - 'a'] < 0) {
                return false; // Early exit! No need to check the rest.
            }
        }
        
        return true;
    }
};
