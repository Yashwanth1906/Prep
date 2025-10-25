#include <bits/stdc++.h>
using namespace std;

pair<int,int> findNode(int n, unordered_map<int,vector<int>>& g, int source) {
  vector<bool> visited(n , false);
  queue<int> q;
  visited[source] = true;
  q.push(source);
  int farthestNode = 0;
  int diameter = 0;
  while(!q.empty()) {
    int n1 = q.size();
    for(int i = 0; i < n1; i++) {
      int node = q.front();
      q.pop();
      farthestNode = node;
      for(auto neigh : g[node]) {
        if(!visited[neigh]) {
          visited[neigh] = true;
          q.push(neigh);
        }
      }
    }
    diameter++;
  }
  return {farthestNode, diameter - 1}; // subtract 1 to get actual distance
}

int findDiameter(int n, unordered_map<int,vector<int>>& g) {
  auto it = findNode(n, g, 0);
  auto diameter = findNode(n, g, it.first);
  return diameter.second;
}

int main() {
  vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
  vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
  int n = edges1.size() + 1;
  int m = edges2.size() + 1;
  unordered_map<int,vector<int>> g1;
  unordered_map<int,vector<int>> g2;
  for(auto& it : edges1) {
    g1[it[0]].push_back(it[1]);
    g1[it[1]].push_back(it[0]);
  }
  for(auto& it : edges2) {
    g2[it[0]].push_back(it[1]);
    g2[it[1]].push_back(it[0]);
  }
  int diameter1 = findDiameter(n, g1);
  int diameter2 = findDiameter(m, g2);

  cout << "Diameter1: " << diameter1 << endl;
  cout << "Diameter2: " << diameter2 << endl;
}
