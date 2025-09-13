#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<int> arr = {4,2,1,3,5};
  int n = arr.size();
  for(int i = 0; i < n - 1;i++) {
    int min_ind = i;
    for(int j = i + 1; j < n;j++) {
      if(arr[j] < arr[min_ind]) {
        min_ind = j;
      }
    }
    swap(arr[i], arr[min_ind]);
  } 
  for(auto& it : arr) {
    cout<<it<<" ";
  }
  cout<<endl;
}
