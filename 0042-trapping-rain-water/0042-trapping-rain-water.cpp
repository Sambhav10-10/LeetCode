class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int lm = 0;
        int rm = 0;
        int ans = 0;

        while (i < j) {

            if (height[i] <= height[j]) {

                if (height[i] >= lm) {
                    lm = height[i];
                }
                else {
                    ans += lm - height[i];
                }

                i++;
            }
            else {

                if (height[j] >= rm) {
                    rm = height[j];
                }
                else {
                    ans += rm - height[j];
                }

                j--;
            }
        }

        return ans;
    }
};