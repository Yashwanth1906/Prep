#include <vector>
#include <iostream>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<int> arr;
  for(int i = 1;i <= n * n;i++) arr.push_back(i);
  int start = arr.size() - n;
  bool forward = true;
  int steps = 0;
  while(steps < n) {
    if(forward) {
      for(int i = start; i < start + n;i++) {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
      start = start - 1;
      forward = false;
    } else {
      int i = 0;
      for(i = start; i > start - n;i--) {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
      start = i - n + 1;
      forward = true;
    }
    steps++;
  }
}
