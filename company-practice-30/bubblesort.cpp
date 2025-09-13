#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> arr = {4,2,1,3,5};
  int n = arr.size();
  bool swapped = false;
  for(int i = 0; i < n - 1;i++) {
    swapped = false;
    for(int j = i + 1; j < n;j++) {
      if(arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
        swapped = true;
      }
    }
    if(!swapped) break;
  }
  for(auto& it : arr) {
    cout<<it<<" ";
  }
  cout<<endl;
}
