#include <bits/stdc++.h>
using namespace std;



int main() {
  int n1, m1;
  cin>>n1>>m1;
  vector<vector<int>> mat1(n1, vector<int>(m1,0));
  for(int i = 0; i < n1;i++) {
    for(int j= 0;  j < m1;j++) {
      cin>>mat1[i][j];
    }
  }
  int n2, m2;
  cin>>n2>>m2;
  if(m1 != n2) {
    cout<<"Can't be multiplied.."<<endl;
    return 1;
  }
  vector<vector<int>> mat2(n2, vector<int>(m2,0));
  for(int i = 0; i < n2;i++) {
    for(int j = 0; j < m2;j++) {
      cin>>mat2[i][j];
    }
  }

  int fn = min(n1, n2), fm = max(m1,m2);

  vector<vector<int>> ans(fn, vector<int>(fm,0));

  for(int i = 0; i < fn;i++) {
    for(int j = 0; j < fm;j++) {
      int x = i, y = j;
      int curry = 0, currx = 0;
      int sum = 0;
      while(curry < fm && currx < fn) {
        sum += mat1[x][curry] * mat2[currx][j];
        curry++;
        currx++;
      }
      ans[x][y] = sum;
    }
  }
  for(auto& it : ans) {
    for(auto& i : it) cout<<i<<" ";
    cout<<endl;
  }
}




// 1 2 3 4    1 2 3           
// 3 4 5 6    6 7 8
// 6 7 8 7    9 9 10
//            10 11 12
//
//
