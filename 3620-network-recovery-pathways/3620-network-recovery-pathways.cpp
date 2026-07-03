class Solution {
private:
    int check(int mid,vector<vector<int>>& edges, vector<bool>& online, long long k,vector<int>& topo,int n){
        const long long INF = 1e18;
        vector<long long> dist(n,INF);
        dist[0] = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(w<mid) continue;
            if(v != n-1 && !online[v]) continue;
            if(u != 0 && !online[u]) continue;
            adj[u].push_back({v,w});
        } 
        for(int u : topo) {
            if(dist[u] == INF) continue;
            for(auto &[v,w] : adj[u]) {
                if(dist[v]>dist[u]+w) dist[v] = dist[u] + w;
            }
        }
        return dist[n-1] <= k; 
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int m = edges.size();
        int n = online.size();
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        int low = 0,high = 0; 
        for(int i=0 ; i<m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back(v);
            indegree[v]++;
            high = max(high,w);
        }
        queue<int> q;
        for(int i=0 ; i<n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto v : graph[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,edges,online,k,topo,n)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};