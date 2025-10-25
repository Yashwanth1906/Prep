#include <bits/stdc++.h>

using namespace std;


int main() {
  string url, hashString;
  int k;
  cin>>url>>hashString>>k;
  url = "https://caayxdycdzwxwac.com";
  hashString = "awpixaia";
  k = 7;
  int m = hashString.size(), n = url.size();
  int curr = 0;
  string ans = "";
  for(int i = 0; i < n;i++) {
    char ch = url[i];
    int val = 0;
    if(ch == ':') {
      val = 26;
    } else if (ch == '/') {
      val = 27;
    } else if (ch == '.') {
      val = 28;
    } else {
      val = ch - 'a';
    }
    if(i!= 0 && i % k == 0) {
      cout<<"i : "<<i<<endl;
      curr = curr % m;
      cout<<"curr : "<<curr<<endl;
      ans.push_back(hashString[curr]);
      curr = val;
    } else {
      curr += val;
    }
  }
  curr = curr % m;
  ans.push_back(hashString[curr]);
  cout<<ans<<endl;
}
