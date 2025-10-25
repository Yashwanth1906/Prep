#include <bits/stdc++.h>
using namespace std;


int countSubDir(string& start, unordered_set<string>& removed, unordered_map<string, vector<string>>& g) {
  int ans = 1;
  for(auto& sub : g[start]) {
    if(removed.find(sub) != removed.end()) continue;
    ans += countSubDir(sub, removed, g);
  }
  return ans;
}


int main() {
  // vector<pair<string, string>> adj  = {{"folder-1", "a"}, {"folder-1", "b"}, {"folder-1", "c"}, {"a", "d"}, {"a", "e"}, {"e", "f"}, {"c", "g"}};
  vector<pair<string, string>> adj  = {{"folder-1", "folder-2"}, {"folder-2", "folder-3"}, {"folder-2", "folder-4"}, {"a", "d"}, {"a", "e"}, {"e", "f"}, {"c", "g"}};
  //vector<string> queries = {"mkdir d h", "rmdir e", "count_subdir a"};
  vector<string> queries = {"mkdir folder-1 folder-5", "count_subdir folder-2", "count_subdir folder-1"};
  unordered_map<string, vector<string>> g;
  for(auto& it : adj) {
    g[it.first].push_back(it.second);
  }
  unordered_set<string> removed;
  for(string& cmd : queries) {
    string temp = "";
    vector<string> vals;
    for(char& it : cmd) {
      if(it == ' ') {
        vals.push_back(temp);
        temp = "";
      } else {
        temp += it;
      }
    }
    vals.push_back(temp);
    if(vals.size() == 3) {
      // cout<<vals[1]<<" "<<vals[2]<<endl;
      if(removed.find(vals[2]) != removed.end()) removed.erase(vals[2]);
      g[vals[1]].push_back(vals[2]);
    } else if(vals[0] == "rmdir") {
      g.erase(vals[1]);
      removed.insert(vals[1]);
    } else {
      cout<<countSubDir(vals[1], removed, g)<<endl;
    }
  }
}
