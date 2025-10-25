#include <bits/stdc++.h>
using namespace std;

pair<int,vector<int>> func(unordered_map<int, vector<pair<int,int>>>& graph, int source, int destination, int n) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,source});
  vector<bool> visited(n ,false);
  vector<int> path;
  while(!pq.empty()) {
    int dist , node;
    tie(dist, node) = pq.top();
    pq.pop();
    path.push_back(node);
    visited[node] = true;
    if(node == destination) return {dist, path};
    for(auto& it : graph[node]) {
      if(visited[it.second] == false) {
        pq.push({dist + it.first, it.second});
      }
    }
  }
  return {-1, {}};
}




int main() {
 vector<vector<int>> adj = {
  {0, 4, 2, 0, 0, 0},  // Edges from 0: 0->1 (4), 0->2 (2)
  {4, 0, 1, 5, 0, 0},  // Edges from 1: 1->0 (4), 1->2 (1), 1->3 (5)
  {2, 1, 0, 8, 10, 0}, // Edges from 2: 2->0 (2), 2->1 (1), 2->3 (8), 2->4 (10)
  {0, 5, 8, 0, 2, 6},  // Edges from 3: 3->1 (5), 3->2 (8), 3->4 (2), 3->5 (6)
  {0, 0, 10, 2, 0, 3}, // Edges from 4: 4->2 (10), 4->3 (2), 4->5 (3)
  {0, 0, 0, 6, 3, 0}   // Edges from 5: 5->3 (6), 5->4 (3)
  };



  unordered_map<int, vector<pair<int,int>>> graph;
  int n = adj.size();
  int m = adj[0].size();
  for(int i = 0; i < n;i++) {
    for(int j = 0; j < m;j++) {
      if(adj[i][j] != 0) {
        graph[i].push_back({adj[i][j], j});
      }
    }
  }

  int source = 0, destination = 3;
  int dist;
  vector<int> path;
  tie(dist, path) = func(graph, source, destination, n);
  cout<<"Distance : "<<dist<<endl;
  cout<<"Path : ";
  for(auto& it : path) cout<<it<<" ";
  cout<<endl;
}
