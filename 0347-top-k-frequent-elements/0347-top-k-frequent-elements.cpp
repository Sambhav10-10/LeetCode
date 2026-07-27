class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        int n = nums.size();

        vector<vector<int>>poyus(n+1);

        for(auto it:mp){
            poyus[it.second].push_back(it.first);
        }
        vector<int>ans;

        for(int i=n; i>=0; i--){
            for(auto num: poyus[i]){
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
        }

        return ans;

    }
};