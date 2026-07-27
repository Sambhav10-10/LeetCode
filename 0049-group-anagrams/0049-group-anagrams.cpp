class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<map<char,int>> freq;

        
        for(int i = 0; i < strs.size(); i++) {
            map<char,int> mp;
            for(int j = 0; j < strs[i].size(); j++) {
                mp[strs[i][j]]++;
            }
            freq.push_back(mp);
        }

        vector<vector<string>> ans;
        vector<int> vis(strs.size(), 0);

        for(int i = 0; i < strs.size(); i++) {
            if(vis[i]) continue;

            vector<string> temp;
            temp.push_back(strs[i]);
            vis[i] = 1;

            for(int j = i + 1; j < strs.size(); j++) {
                if(!vis[j] && freq[i] == freq[j]) {
                    temp.push_back(strs[j]);
                    vis[j] = 1;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};