class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> mp;

        
        for (auto &x : reservedSeats) {
            if (mp.find(x[0]) == mp.end())
                mp[x[0]] = vector<bool>(11, false);
            mp[x[0]][x[1]] = true;
        }

       
        int ans = (n - mp.size()) *2;

        for (auto &it : mp) {
            vector<bool> used = it.second; 

           
            if (!used[2] && !used[3] && !used[4] && !used[5]) {
                ans++;
                used[2] = used[3] = used[4] = used[5] = true;
            }

            if (!used[4] && !used[5] && !used[6] && !used[7]) {
                ans++;
                used[4] = used[5] = used[6] = used[7] = true;
            }

          
            if (!used[6] && !used[7] && !used[8] && !used[9]) {
                ans++;
                used[6] = used[7] = used[8] = used[9] = true;
            }
        }

        return ans;
    }
};