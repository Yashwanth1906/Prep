#include <bits/stdc++.h>
using namespace std;
typedef  pair<int,int> pii;

vector<int> dijkstra(int n, vector<vector<pii>> adj,int source) {
  vector<int> dist(n,1e9);
  dist[source] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq; // Min heap
  pq.push({0, source});
  while(!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();
    if(cost > dist[u]) continue;
    for(auto node : adj[u]) {
      int v = node.first;
      int weight = node.second;
      if(dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
} 

int main() {
   int V = 5;
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 1});
    adj[3].push_back({0, 1});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[2].push_back({4, 5});
    adj[4].push_back({2, 5});

    adj[3].push_back({4, 2});
    adj[4].push_back({3, 2});

    vector<int> dist = dijkstra(V, adj, 0);
    for (int i = 0; i < V; ++i) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << '\n';
    }
}
