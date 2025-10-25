#include <iostream>
using namespace std;


int main() {
  string s;
  getline(cin,s);
  cout<<s<<endl;
  string ans = "";
  for(char& it : s) {
    if(it == ' ') {
      ans += "%20";
    } else {
      ans += it;
    }
  }
  cout<<ans<<endl;
}
