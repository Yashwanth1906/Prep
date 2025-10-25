#include <bits/stdc++.h>
using namespace std;


string minString(string& s) {
  string ans = s;
  unordered_map<char, int> track;
  for(char& it : s) track[it]++;
  vector<char> odds;
  for(auto& it : track) {
    if(it.second % 2 == 1) {
      odds.push_back(it.first);
    }
  }
  if(odds.size() > 1) {
    sort(odds.begin(), odds.end());
    for(int i = 0; i < odds.size() / 2;i++) {
      char ch1 = odds[i];
      char ch2 = odds[odds.size() - i - 1];
      cout<<ch1<<" "<<ch2<<endl;
      track[ch1]++;
      track[ch2]--;
    }
  }
  for(auto& it : track) {
    cout<<it.first<<" : "<<it.second<<endl;
  }
  priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> pq1;
  for(auto& it : track) pq1.push(it);
  char oddy = '0';
  int start = 0, end = s.size() - 1;
  while(!pq1.empty()) {
    char ch;
    int val;
    ch = pq1.top().first;
    val = pq1.top().second;
    pq1.pop();
    for(int i = 0; i < (int)val / 2; i++) {
      ans[start++] = ch;
      ans[end--] = ch;
    }
    if(val % 2 == 1) oddy = ch;
  }
  cout<<oddy<<endl;
  if(oddy != '0') {
    ans[ans.size() / 2] = oddy;
  }
  return ans;
}


int main() {
  string s;
  cin>>s;
  cout<<minString(s)<<endl;
}
