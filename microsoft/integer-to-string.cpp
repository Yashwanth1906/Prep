#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  string number = to_string(n);
  stack<string> ans;
  unordered_map<string, string> track = {
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
        {"4", "four"},
        {"5", "five"},
        {"6", "six"},
        {"7", "seven"},
        {"8", "eight"},
        {"9", "nine"},
        {"0", "zero"},
        {"10", "ten"},
        {"11", "eleven"},
        {"12", "twelve"},
        {"13", "thirteen"},
        {"14", "fourteen"},
        {"15", "fifteen"},
        {"16", "sixteen"},
        {"17", "seventeen"},
        {"18", "eighteen"},
        {"19", "nineteen"},
        {"20", "twenty"},
        {"30", "thirty"},
        {"40", "forty"},
        {"50", "fifty"},
        {"60", "sixty"},
        {"70", "seventy"},
        {"80", "eighty"},
        {"90", "ninety"} // fixed spelling from "ninty"
    };
  if(number.size() <= 0) {
    cout<<"Invalid Number"<<endl;
    return 0;
  }  
  if(number.size() == 1) {
    cout<<track[number]<<endl;
  }
  unordered_map<int,string> places  = {
    {1 , "tens"}, 
    {2 , "hundreds"},
    {3 , "thousands"}, 
    {4, "ten-thousand"},
    {5, "lakhs"},
    {6, "tenlakhs"},
    {7, "crores"}, 
    {8, "tencrores"},
    {9, "hundredcrores"}
  };
    stack<char> vals;
  for(auto& it : number) {
    vals.push(it);
  }
  int step = 0;
  string temp = "";
  while(!vals.empty()) {
    char ch = vals.top();
    vals.pop();
    if(step == 0) {
      temp += ch;
      ans.push(track[string(1, ch)]);
    }
    if(step == 1) {
      if(ch == '1') {
        ans.pop();
        temp = ch + temp;
        ans.push(track[temp]);
      } else {
        if(ans.top() == "zero") ans.pop();
        string t = string(1, ch) + string("0");
        cout<<"Char : "<<ch<<endl;
        cout<<t<<endl;
        ans.push(track[t]);
      }
      temp = "";
    }
    if(step == 2) {
      ans.push(track[string(1,ch)] + string(" hundred and "));
    }
    if(step == 3) {
      temp += ch;
      ans.push(track[string(1,ch)] + string(" thousand and "));
    }
    if(step == 4) {
      if(ch == '1') {
        ans.pop();
        temp = ch + temp;
        ans.push(track[temp] + " thousand and ");
      }
      else {
        string t = string(1, ch) + string("0");
        if(temp == "0") {
          ans.pop();
          ans.push(track[t] + " thousand and ");
        } else {
          ans.push(track[t]);
        }
      }
      temp = "";
    }
    step++;
  }
  while(!ans.empty()) {
    cout<<ans.top()<<" ";
    ans.pop();
  }
}
