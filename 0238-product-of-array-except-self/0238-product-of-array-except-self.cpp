class Solution {
public:
    int leftRec(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) return 1;

        if (dp[i] != -1) return dp[i];

        return dp[i] = nums[i - 1] * leftRec(i - 1, nums, dp);
    }

    int rightRec(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (i == n - 1) return 1;

        if (dp[i] != -1) return dp[i];

        return dp[i] = nums[i + 1] * rightRec(i + 1, nums, dp);
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, -1), right(n, -1), ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = leftRec(i, nums, left) * rightRec(i, nums, right);
        }

        return ans;
    }
};