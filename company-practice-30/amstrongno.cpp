#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cout<<"The amstrong no from 1 to 1000 are ";
  for(int i = 1; i <= 1000;i++) {
    ll ans = 0;
    string no = to_string(i);
    int size = no.size();
    for(auto& it : no) {
      int n = it - '0';
      ans += pow(n, size);
    }
    if(ans == i) {
      cout<<i<<" ";
    }
  }
  cout<<endl;
}
