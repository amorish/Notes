class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Container to hold all triplets
        int n = nums.size(); 
        
        // Correct C++ sorting syntax
        sort(nums.begin(), nums.end());
        
        // Loop up to the third-to-last element
        for(int i = 0; i < n - 2; i++) {
            
            // Skip duplicate values for the 'i' pointer
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == 0) {
                    // 1. Store the triplet instead of returning
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    // 2. Skip duplicate values for 'l' and 'r'
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    
                    // 3. Move both pointers to continue searching
                    l++;
                    r--;
                } 
                else if(sum < 0) {
                    l++;
                } 
                else {
                    r--;
                }
            }
        }
        
        // Return the full list of collected triplets
        return ans; 
    }
};
