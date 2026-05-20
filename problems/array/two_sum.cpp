class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /* ==========================================
           1. BRUTE FORCE (Nested Loops)
           Time: O(N^2) | Space: O(1)
           Idea: Check every possible pair.
           ========================================== */
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        
        
        /* ==========================================
           2. BETTER (Two-Pass Hash Map)
           Time: O(N) | Space: O(N)
           Idea: Store all elements first, then check for target - nums[i].
           ========================================== */
        // unordered_map<int, int> seen;
        // for (int i = 0; i < nums.size(); i++) {
        //     seen[nums[i]] = i;
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     int diff = target - nums[i];
        //     if (seen.count(diff) && seen[diff] != i) {
        //         return {i, seen[diff]};
        //     }
        // }


        /* ==========================================
           3. BEST (One-Pass Hash Map)
           Time: O(N) | Space: O(N)
           Idea: Find complement and insert current number in one loop.
           ========================================== */
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            // Check if complement already exists
            auto it = seen.find(diff);
            if (it != seen.end()) {
                return {it->second, i}; // Found the pair
            }
            
            // Otherwise, store current number and its index
            seen[nums[i]] = i;
        }
        
        return {};
    }
};
