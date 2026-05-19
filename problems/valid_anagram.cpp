class Solution {
public:
    /*
    1. BRUTE FORCE (Sorting): O(N log N) time | O(1) space
       sort(s.begin(), s.end()); sort(t.begin(), t.end()); return s == t;

    2. BETTER (Hash Map): O(N) time | O(K) space
       unordered_map<char, int> m; for(char c:s) m[c]++; for(char c:t) if(--m[c]<0) return false;
    */

    // 3. BEST (Frequency Vector): O(N) time | O(1) space (Fixed 26)
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> ccount(26,0);
        
        for(int i = 0; i<s.size(); i++){
            ccount[s[i]-'a']++;
            ccount[t[i]-'a']--;
        }

        for(int it: ccount){
            if(it!=0) return false;
        }

        return true;
    }
};
