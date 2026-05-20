class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1, maxv = 0;
        while(l<r){
            int w = r-l;
            int h = min(heights[l],heights[r]);
            int vol = w*h;
            maxv = max(maxv,vol);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxv;
    }
};
