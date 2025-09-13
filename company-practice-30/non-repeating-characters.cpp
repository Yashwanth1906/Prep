#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  unordered_map<char,int> track;
  for(auto& it : s) track[it]++;
  for(auto& it : s) {
    if(track[it] == 1) {
      cout<<"The first non-repeating character is "<<it<<endl;
      return 0;
    }
  }
  cout<<"All the characters are repeating in the string."<<endl;
}
