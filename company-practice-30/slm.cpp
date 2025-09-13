#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n;i++) cin>>arr[i];
  cout<<"The smallest element is "<<*min_element(arr.begin(), arr.end())<<endl;
  cout<<"The largest element is "<<*max_element(arr.begin(), arr.end())<<endl;
  cout<<"The middle element is "<<arr[ n / 2]<<endl;
}
