#include <bits/stdc++.h>
using namespace std;




int main() {
  vector<int> arr = {25,10,20};
  priority_queue<int,vector<int>, greater<int>> pq;
  for(auto& it : arr) pq.push(it);
  int ans = 0;
  while(!pq.empty()) {
    int ele1 = pq.top();
    pq.pop();
    if(pq.empty()) {
      cout<<ans<<endl;
      return 0;
    }
    int ele2 = pq.top();
    pq.pop();
    cout<<ele1<<" "<<ele2<<endl;
    ans += ele1 + ele2;
    pq.push(ele1 + ele2);
  }
  cout<<ans<<endl;
  return 0;
}
