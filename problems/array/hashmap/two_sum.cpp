class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
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
