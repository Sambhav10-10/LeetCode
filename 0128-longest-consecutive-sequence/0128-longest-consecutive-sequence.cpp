class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int cnt=mp[0].second;
        for(int i=0;i<mp.size()-1;i++){
            
            if(mp[i].first==mp[i+1].first){
                cnt=cnt+mp[i+1].second;
            }
            else{
                cnt=mp[i+1].second;
            }
        }
        return cnt;
    }
};