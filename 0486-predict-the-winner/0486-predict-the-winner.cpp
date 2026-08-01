class Solution {
public:
    int solve(int i, int j, vector<int>& nums, int check) {
        if (i > j) return 0;

        if (check % 2 == 0) { 
            return max(nums[i] + solve(i + 1, j, nums, check + 1),
                       nums[j] + solve(i, j - 1, nums, check + 1));
        } else { 
            return min(solve(i + 1, j, nums, check + 1),
                       solve(i, j - 1, nums, check + 1));
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int total = 0;
        for (int x : nums)
            total += x;

        int p1 = solve(0, nums.size() - 1, nums, 0);
        int p2 = total - p1;

        return p1 >= p2;
    }
};