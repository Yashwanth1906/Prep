#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<vector<int>>& x, vector<string>& commands) {
  int n = x.size(), m = x[0].size();
  for(auto& it : commands) {
    string cmd = "";
    int val1 = -1, val2 = -1;
    string temp = "";
    for(auto& i : it) {
      if(i == ' ') {
        if(cmd.size() == 0) {
          cmd = temp;
        } else {
          int x = stoi(temp);
          if(val1 == -1) val1 = x;
        }
        temp = "";
      } else {
        temp += i;
      }
    }
    if(cmd.size() == 0) {
      cmd = temp;
    } else if (val1 == -1 || val2 == -1) {
      int x = stoi(temp);
      if(val1 == -1) val1 = x;
      else val2 = x;
    }
    cout<<cmd<<" "<<val1<<" "<<val2<<endl;
    if (cmd == "swapRows") {
    for (int i = 0; i < m; i++) {
        swap(x[val1][i], x[val2][i]);
    }
} else if (cmd == "swapColumns") {
    for (int i = 0; i < n; i++) {
        swap(x[i][val1], x[i][val2]);
    }
} else if (cmd == "reverseRow") {
    reverse(x[val1].begin(), x[val1].end());
} else if (cmd == "reverseColumn") {
    for (int i = 0; i < n / 2; i++) {
        swap(x[i][val1], x[n - i - 1][val1]);
    }
} else if (cmd == "rotate90Clockwise") {
    // Your code for 90-degree rotation
} else {
    // Handle unknown command
}
  }
  return x;
}



int main() {
  vector<vector<int>> x= {{1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7}};
  vector<string> commands = {"swapRows 0 2", "swapColumns 1 2", "reverseRow 0", "reverseColumn 2", "rotate90Clockwise"};
  vector<vector<int>> ans = func(x, commands);
  for(auto& it : ans) {
    for(auto& i : it) cout<<i<<" ";
    cout<<endl;
  }
} 
