class Solution {
public:
    void leftRec(int i, int prod, vector<int>& nums, vector<int>& left) {
        if (i == nums.size()) return;

        left[i] = prod;
        leftRec(i + 1, prod * nums[i], nums, left);
    }

    void rightRec(int i, int prod, vector<int>& nums, vector<int>& right) {
        if (i < 0) return;

        right[i] = prod;
        rightRec(i - 1, prod * nums[i], nums, right);
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n), ans(n);

        leftRec(0, 1, nums, left);
        rightRec(n - 1, 1, nums, right);

        for (int i = 0; i < n; i++)
            ans[i] = left[i] * right[i];

        return ans;
    }
};