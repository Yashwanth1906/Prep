#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
  int n;
  cin>>n;
  int ans = int(n / 5);
  if(n % 5 != 0) ans++;
  cout<<ans<<endl;
}
