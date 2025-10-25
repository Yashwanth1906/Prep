#include <bits/stdc++.h>
using  namespace std;

class DisjointSet {
  vector<int> parent, size;
public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for(int i  = 0; i <= n;i++) {
      parent[i] = i;
    }
  }
  int findParent (int node) {
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
  }
  void join(int u, int v) {
    int parentu = findParent(u);
    int parentv = findParent(v);
    if(parentu == parentv) return;
    if(size[parentu] < size[parentv]) {
      parent[parentu] = parentv;
      size[parentv] += size[parentu];
    } else {
      parent[parentv] = parentu;
      size[parentu] += size[parentv];
    }
  }
};


int main() {
  DisjointSet ds(10);
  ds.join(1,2);
  ds.join(2,3);
  cout<<ds.findParent(1)<<endl;
}
