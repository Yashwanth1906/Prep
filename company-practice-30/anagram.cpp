#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin>>a;
  cin>>b;
  unordered_map<char,int> track1;
  unordered_map<char,int> track2;
  for(auto& it : a) {
    track1[it]++;
  }
  for(auto& it : b) {
    track2[it]++;
  }
  for(auto& it : track2) {
    if(it.second != track1[it.first]) {
      cout<<"Not an Anagarm"<<endl;
      return 0;
    }
  }
  cout<<"The given string is an Anagarm."<<endl;
}
