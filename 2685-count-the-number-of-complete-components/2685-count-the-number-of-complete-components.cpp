class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (int i = 0; i < adj[node].size(); i++) {
            int nei = adj[node][i];
            if (!vis[nei]) {
                dfs(nei, adj, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                
                vector<int> comp;                    
                dfs(i, adj, vis, comp);              

                int nodes = comp.size();
                int edgesCount = 0;

                for (int j = 0; j < comp.size(); j++) {
                    edgesCount += adj[comp[j]].size();
                }

                edgesCount /= 2; 

                if (edgesCount == (nodes * (nodes - 1)) / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};