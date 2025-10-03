#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll try_combination(ll n, ll m, ll x, ll y) {
  ll max_patients = 0;
  for (ll p1 = 0; p1 <= 1000000; ++p1) {
      if (x * p1 > n || y * p1 > m) break;
        ll rem_n = n - x * p1;
        ll rem_m = m - y * p1;
        ll p2 = min(rem_n / y, rem_m / x);
        max_patients = max(max_patients, p1 + p2);
    }
    return max_patients;
}

int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll ans1 = try_combination(n, m, x, y);
    ll ans2 = try_combination(n, m, y, x);

    cout << max(ans1, ans2) << endl;

    return 0;
}

