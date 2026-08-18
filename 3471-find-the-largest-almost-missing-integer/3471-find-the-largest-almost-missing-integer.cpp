class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int cnt1 = 0, cnt2 = 0;
        int m = nums[0];
        int n = nums[nums.size() - 1];

        
        if (k == 1) {
            int ans = -1;

            for (int i = 0; i < nums.size(); i++) {
                int cnt = 0;

                for (int j = 0; j < nums.size(); j++) {
                    if (nums[i] == nums[j])
                        cnt++;
                }

                if (cnt == 1)
                    ans = max(ans, nums[i]);
            }

            return ans;
        }

       
        if (k > 1 && k < nums.size()) {

            
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == m)
                    cnt1++;
            }

            
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == n)
                    cnt2++;
            }

            if (cnt1 == 0 && cnt2 != 0)
                return m;

            else if (cnt1 != 0 && cnt2 == 0)
                return n;

            else if (cnt1 == 0 && cnt2 == 0)
                return max(m, n);

            else
                return -1;
        }

  
        return *max_element(nums.begin(), nums.end());
    }
};