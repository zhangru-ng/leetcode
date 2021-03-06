// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.

// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        int i = 0;
        while (i < height.size()) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top();
                st.pop();
                if (!st.empty()) {
                    water += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
                }
            }
        }
        return water;
    }
};
