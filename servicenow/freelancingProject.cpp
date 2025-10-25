#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> projectId = {0,1,0,1,1};
  vector<int> bid = {4,74,47,744,7};
  unordered_map<int,int> track;
  for(int i = 0; i < (int)projectId.size();i++) { 
      int it = projectId[i];
      int b = bid[i];
    if(track.find(it) != track.end()) {
      track[it] = min(track[it], b);
    } else {
      track[it] = b;
    }
  }
  int ans = 0;
  for(auto& it : track) {
    ans += it.second;
  }
  cout<<ans<<endl;
}
