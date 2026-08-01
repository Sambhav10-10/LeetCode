class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums, int check) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (check % 2 == 0) { 
            return dp[i][j] = max(
                nums[i] + solve(i + 1, j, nums, check + 1),
                nums[j] + solve(i, j - 1, nums, check + 1)
            );
        } else {
            return dp[i][j] = min(
                solve(i + 1, j, nums, check + 1),
                solve(i, j - 1, nums, check + 1)
            );
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));

        int total = 0;
        for (int x : nums) total += x;

        int p1 = solve(0, n - 1, nums, 0);
        int p2 = total - p1;

        return p1 >= p2;
    }
};