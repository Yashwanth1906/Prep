#include <iostream>
using namespace std;
#include <vector>

int main() {
  int n;
  cin>>n;
  vector<int> ans;
  for(int i = 0; i <= n;i++) {
    int countof1 = 0;
    int val = i;
    while(val != 0) {
      countof1 += (val % 2);
      val /= 2;
    }
    ans.push_back(countof1);
  }
  for(auto& it : ans) {
    cout<<it<<endl;
  }
}
