#include <iostream>
using namespace std;

int main() {
  int n, ans = 0;
  cin>>n;
  string arr[n];
  for(int i = 0; i < n;i++) cin>>arr[i];
  for(int i = 0; i < n;i++) {
    string s = arr[i];
  int age = stoi(string(1, s[11]) + string(1, s[12]));
  cout<<"Age : "<<age<<endl;
  if(age >= 60) {
    ans++;
  }
  }
  cout<<ans<<endl;
}
