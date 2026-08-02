class Solution {
public:
int solve(int i,int j,vector<int>&piles,int check,vector<vector<int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
     if (check % 2 == 0) { 
            return dp[i][j]=max(piles[i] + solve(i + 1, j, piles, check + 1,dp),
                       piles[j] + solve(i, j - 1, piles, check + 1,dp));
        } else { 
            return dp[i][j]=min(solve(i + 1, j, piles, check + 1,dp),
                       solve(i, j - 1, piles, check + 1,dp));
        }
}
    bool stoneGame(vector<int>& piles) {
        int i=0;
        int n=piles.size();
        int j=n-1;
        int check=0;
        int total=0;
      vector<vector<int>> dp(n, vector<int>(n, -1));
        for(auto it:piles){
            total+=it;
        }
        int p1=solve(i,j,piles,check,dp);
        int p2=total-p1;
        return p1>p2;
    }
};