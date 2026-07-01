class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,-1},{0,1},{-1,0}};
    bool fn(vector<vector<int>>& dist,int pos) {
        int n = dist.size();
        if(dist[0][0]<pos) return false;
        vector<vector<int>> vis(n,vector<int> (n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({dist[0][0],{0,0}});
        vis[0][0] = 1;
        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1) return true;
            for(auto& dir : directions){
                int r = i + dir[0];
                int c = j + dir[1];
                if(r>=0 && c>=0 && r<n && c<n && !vis[r][c] && dist[r][c]>=pos) {
                    vis[r][c] = 1;
                    pq.push({dist[r][c],{r,c}});
                }
            }
        }
        return false;
    }
    void bfs(vector<pair<int,int>> theives,vector<vector<int>>& grid,vector<vector<int>>& dist){
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<pair<int,pair<int,int>>> pq;
        int m = theives.size();
        for(int i=0 ; i<m ; i++) {
            dist[theives[i].first][theives[i].second] = 0;
            pq.push({0,{theives[i].first,theives[i].second}});
            vis[theives[i].first][theives[i].second] = 1;
        }
        while(!pq.empty()){
            int d = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();
            for(auto& dir : directions) {
                int r = row + dir[0];
                int c = col + dir[1];
                if(r>=0 && c>=0 && r<n && c<n && !vis[r][c]) {
                    vis[r][c] = 1;
                    dist[r][c] = d+1;
                    pq.push({d+1,{r,c}});
                }
            }
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]) return 0;
        vector<vector<int>> dist(n,vector<int> (n,2*(n-1)));
        vector<pair<int,int>> theives;
        for(int i=0 ; i<n ; i++) {
            int cnt = 0;
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                    theives.push_back({i,j});
                }
            }
            if(cnt == n) return 0;
        }
        bfs(theives,grid,dist);
        int low = 0 , high = 2*(n-1);
        int ans = 2*(n-1);
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(fn(dist,mid)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};