#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin>>n;
  ll ans = 1;
  for(ll i = n; i >= 2;i--) ans *= i;
  cout<<"The factorial of "<<n<<" is "<<ans<<endl;
}
