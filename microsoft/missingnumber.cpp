#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n - 1;i++) {
    cin>>arr[i];
  }
  int actualSum = n * (n + 1) / 2;
  int gotSum = 0;
  for(int i = 0; i < n - 1;i++) {
    cout<<arr[i]<<endl;
    gotSum += arr[i];
  }
  cout<< actualSum - gotSum;
}
