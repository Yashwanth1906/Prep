class Solution {
public:
    unordered_map<int,vector<int>> graph;
    int timer = 1;
    vector<vector<int>> ans;
    void dfs(int node, int parent, vector<int>& visited, int tin[], int low[]) {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto neigh : graph[node]) {
            if(neigh == parent) continue;
            if(visited[neigh] == 0) {
                dfs(neigh, node, visited, tin, low);
                low[node] = min(low[node], low[neigh]);
                if(low[neigh] > tin[node]) ans.push_back({neigh, node});
            } else {
                low[node] = min(low[node], low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        for(auto -0poppppppppppppppp[pit : conn) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int tin[n];
        int low[n];
        dfs(0, -1, visited, tin, low);
        return ans;
    }
};

