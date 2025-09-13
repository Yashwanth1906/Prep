#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<vector<int>> ans(n, vector<int>(n));
  for(int i = 1; i <= n;i++) {
    int rowStart = i - 1;
    int rowEnd = n - i;
    int colStart = i - 1;
    int colEnd = n - i;
    for(int j = colStart; j <= colEnd;j++) {
      ans[rowStart][j] = i;
      ans[rowEnd][j] = i;
    }
    for(int j = rowStart; j <= rowEnd;j++) {
      ans[j][colStart] = i;
      ans[j][colEnd] = i;
    }
  }
  for(auto it : ans) {
    for(auto i : it) {
      cout<<i<<" ";
    }
    cout<<endl;
  }
}
