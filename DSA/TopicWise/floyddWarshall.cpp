#include <bits/stdc++.h>
using namespace std;

void floydWarshal(vector<vector<int>>& dist, int n) {
  for(int k = 0; k < n;k++) {
    for(int i = 0; i < n;i++) {
      for(int j = 0; j < n;j++) {
        if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {
  int n = 4;
  vector<vector<int>> dist(n, vector<int>(n, 1e9));
  for(int i = 0; i < n;i++) dist[i][i] = 0;
  dist[0][1] = 5;
  dist[0][3] = 10;
  dist[1][2] = 3;
  dist[2][3] = 1;
  floydWarshal(dist,n);
  for(auto it : dist) {
    for(auto i : it) cout<<i<<" ";
    cout<<endl;
  }
}
