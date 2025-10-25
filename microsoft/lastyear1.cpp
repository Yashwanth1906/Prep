#include <bits/stdc++.h>
using namespace std;

int func(int x, int y, vector<vector<int>>& arr, vector<vector<int>>& dp) {
  if(x == 1 && y == arr[0].size() - 1) {
    return arr[x][y];
  }
  if(dp[x][y] != -1) return dp[x][y];
  int right = 1e9, down = 1e9;
  if(y + 1 < arr[0].size()) {
    right = arr[x][y] + func(x, y + 1, arr,dp);
  }
  if(x + 1 < 2) {
    down = arr[x][y] + func(x + 1, y, arr,dp);
  }
  return dp[x][y] = min(right, down);
}



int main() {
  int n;
  cin>>n;
  vector<vector<int>> arr(2, vector<int>(n));
  vector<vector<int>> dp(2, vector<int>(n + 1, 0));
  dp[0][0] = arr[0][0];
  dp[1][n - 1] = arr[1][n - 1];
  for(int i = 0; i < 2;i++) {
    for(int j = 0; j < n;j++) {
      cin>>arr[i][j];
    }
  }
  for(int x = 0; x < 2;x++) {
    for(int y = 0; y < n - 1;y++) {
  int right = 1e9, down = 1e9;
  if(y + 1 < n) {
    right = arr[x][y] + dp[x][y+1];
  }
  if(x + 1 < 2) {
    down = arr[x][y] + dp[x + 1][y];
  }
  dp[x][y] = min(right, down);
    }
  }
  cout<<dp[1][n-1]<<endl;
  cout<<func(0,0, arr, dp)<<endl;
}
