#include <bits/stdc++.h>
using  namespace std;


int main() {
  string encrypted;
  cin>>encrypted;
  int k;
  cin>>k;
  string ans = "";
  for(auto& ch : encrypted) {
    int val = ch - 'A';
    val -= k;
    if(val < 0) {
      val = 26 + val;
    }
    ans.push_back('A' + val);
  }
  cout<<ans<<endl;
}
