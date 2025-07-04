#include <bits/stdc++.h>
using namespace std;

int a[10000] , seg[4 *10000];

void build(int ind, int low, int high) {
  if(low == high) {
    seg[ind] = a[low]; return;
  }
  int mid = low + (high - low) / 2;
  build(2 * ind + 1, low, mid);
  build(2 * ind + 2, mid + 1, high);
  seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {
  if(low >= l && high <= r) {
    return seg[ind];
  }
  if(high < l || low > r) return -1e9;
  int mid = low + (high - low) / 2;
  int left = query(2 * ind + 1, low, mid, l, r);
  int right = query(2 * ind + 2, mid + 1, high , l , r);
  return max(left, right);
}

int main() {
  int n;
  cin>>n;
  for(int i = 0; i < n;i++) {
    cin>>a[i];
  }
  build(0,0, n - 1);
  cout<<query(0,0,n-1,1,4);
}
