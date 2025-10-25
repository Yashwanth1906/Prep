#include <bits/stdc++.h>
using namespace std;

bool func(int mid, vector<int>& arr, int& x, int& y) {
  int extraMoves = 0;
  cout<<"Mid : "<<mid<<endl;
  for(auto& it : arr) {
    if(y * mid >= it) {
      continue;
    } else {
      int remaining = it - y * mid;
      cout<<"remaining : "<<remaining<<endl;
      int temp = (remaining + x - 1) / x;
      extraMoves += temp;
    }
  }
  cout<<"extraMoves : "<<extraMoves<<endl;
  return mid > extraMoves;
}


int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  int maxi = 0;
  for(int i=  0; i <n;i++) {
    cin>>arr[i];
    maxi = max(maxi, arr[i]);
  }
  int x,y;
  cin>>x>>y;
  cout<<"Output------"<<endl;
  int low = (maxi + x - 1)  / x, high = (maxi + y - 1) / y;
  cout<<"Low : "<<low<<" high : "<<high<<endl;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(func(mid, arr,x,y)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout<<low<<" "<<high<<endl;
  cout<<"Ans : "<<ans<<endl;
}
