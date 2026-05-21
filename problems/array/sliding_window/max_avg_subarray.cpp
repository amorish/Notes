class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int wsum = 0;
        // 1st window
        for(int i = 0; i<k; i++){
            wsum += nums[i];
        }

        int maxs = wsum;
        for(int i = k; i<n; i++){
            wsum += nums[i]-nums[i-k];
            maxs = max(maxs, wsum);
        }
        return (double)maxs/k;
    }
};
