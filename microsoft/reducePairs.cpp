#include <bits/stdc++.h>
using namespace std;

int func(int start, int end, vector<int>& arr, int prev) {
  if(start >= end) {
    return 0;
  }
  int front = 0, back = 0, two = 0;
  if(prev == -1) {
    front = 1 + func(start + 2, end, arr, arr[start] + arr[start + 1]);
    back = 1 + func(start, end - 2, arr, arr[end] + arr[end-1]);
    two = 1 + func(start + 1, end - 1, arr, arr[start] + arr[end]);
    return max(front, max(back, two));
  }
  if(arr[start] + arr[start + 1] == prev) {
    front = 1 + func(start + 2, end, arr, prev);
  }
  if(arr[end] + arr[end - 1] == prev) {
    back = 1 + func(start, end- 2, arr, prev);
  }
  if(arr[start] + arr[end] == prev) {
    two = 1 + func(start + 1, end - 1, arr, prev);
  }
  return max(front, max(back, two));
}



int main() {
  vector<int> arr = {4,1,4,3,3,2,5,2};
  cout<<func(0, arr.size() - 1, arr,-1)<<endl;
}
