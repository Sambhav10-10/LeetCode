class Solution {
public:
    string smallestPalindrome(string s) {
        string ans;
    char poyus;

      map<char,int>mp;
      for(auto c:s){
        mp[c]++;
      } 
      for(auto d:mp){
        if(mp[d.first]%2==0){
            int even=mp[d.first]/2;
            while(even>0){
                ans.push_back(d.first);
                even--;
            }
        }
        else{
            int odd=mp[d.first]/2;
            poyus=d.first;
            while(odd>0){
                ans.push_back(d.first);
                odd--;
            }

        }
      }
      int idx;
      
     
      if(s.size()%2!=0){
 ans.push_back(poyus);
        idx=ans.size()-2;
      }
      else{
        idx=ans.size()-1;
      }
      while(idx>=0){
        ans.push_back(ans[idx]);
        idx--;
      }
      return ans;
    }
};