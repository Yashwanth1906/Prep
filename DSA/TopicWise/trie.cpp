#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  TrieNode* links[26];
  bool flag;
  TrieNode() {
    flag = false;
    for(int i = 0; i < 26;i++) links[i] = nullptr;
  }
};

class Trie {
private:
  TrieNode* root;
public:
  Trie() {
    root = new TrieNode();
  }
  void insert(string& word) {
    TrieNode* curr = root;
    for(auto it : word) {
      int ch = it - 'a';
      if(!curr->links[ch]) {
        curr->links[ch] = new TrieNode();
      }
      curr = curr->links[ch];
    }
    curr->flag = true;
  }
  bool searchWord(string word) {
    TrieNode* curr = root;
    for(auto it : word) {
      int ch = it - 'a';
      if(!curr->links[ch]) return false;
      curr = curr->links[ch];
    }
    return curr->flag;
  }
  bool isPrefix(string pref) {
    TrieNode* curr = root;
    for(auto it : pref) {
      int ch = it - 'a';
      if(!curr->links[ch]) return false;
      curr = curr->links[ch];
    }
    return true;
  }
};

int main() {
  vector<string> words = {"hello", "hi", "hel"};
  Trie trie;
  for(auto it : words) {
    trie.insert(it);
  }
  cout<<trie.isPrefix("hele")<<endl;
  cout<<trie.isPrefix("hello")<<endl;
}
