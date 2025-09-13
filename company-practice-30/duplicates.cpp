#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n;i++) cin>>arr[i];
  unordered_map<int,int> track;
  for(auto& it : arr) track[it]++;
  cout<<"The duplicate elements are : ";
  for(auto& it : track) {
    if(it.second > 1) {
      cout<<it.first<<" ";
    }
  }
  cout<<endl;
}
