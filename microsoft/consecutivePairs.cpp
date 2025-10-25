#include <bits/stdc++.h>
using namespace std;

int func(int ind, vector<int>& arr, int prevInd, int prev) {
  if(ind >= arr.size()) return 0;
  int pick = 0;
  if(prevInd == -1) {
    pick = 1 + func(ind + 1, arr, ind, prev);
  } else if (prev == -1) {
    pick = 1 + func(ind + 1, arr, ind, arr[ind] - arr[prevInd]);
  } else {
    if(prev == arr[ind] - arr[prevInd]) {
      pick = 1 + func(ind + 1, arr, ind,prev);
    }
  }
  int notpick = func(ind + 1, arr, prevInd, prev);
  return max(pick, notpick);
}



int main() {
  vector<int> arr = {18,26,18,24,24,20,22}; //input
  sort(arr.begin(), arr.end());
  cout<<func(0, arr, -1, -1)<<endl;
}
