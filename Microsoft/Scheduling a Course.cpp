class Solution {
    
    bool dfs(unordered_set<int> adj[], int i, vector<int> &vis, vector<int> &dfsvis)
    {
        vis[i] = 1, dfsvis[i] = 1;
        for(auto j:adj[i])
        {
            if(vis[j] == 0)
            {
                if(dfs(adj, j, vis, dfsvis))
                    return true;
            }
            else if(dfsvis[j] == 1)
                return true;
        }
        dfsvis[i] = 0;
        return false;
    }
    
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_set<int> adj[n];
        
        for(auto i:prerequisites)
            adj[i[0]].insert(i[1]);
        
        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(adj, i, vis, dfsvis))
                    return false;
            }
        }
        
        return true;
    }
};