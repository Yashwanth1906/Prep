#include <bits/stdc++.h>
using namespace std;


int main() {
  int n = 5;
  vector<vector<int>> dependencies = {{1,0}, {2,0}, {3,1}, {3,2}, {4,3}};

  unordered_map<int, vector<int>> graph;
  vector<int> inorder(n, 0);
  for(auto& it : dependencies) {
    graph[it[1]].push_back(it[0]);
    inorder[it[0]]++;
  }
  stack<int> s;
  vector<int> res;
  for(int i = 0; i < n;i++) {
    if(inorder[i] == 0) s.push(i);
  }
  while(!s.empty()) {
    int node = s.top();
    s.pop();
    res.push_back(node);
    if(res.size() == 5) break;
    for(auto& it : graph[node]) {
      inorder[it]--;
      if(inorder[it] == 0) {
        s.push(it);
      }
    }
  }
  for(auto& it : res) cout<<it<<" ";
  cout<<endl;
}
