#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool func(TreeNode* node, int low, int high) {
    if(node == nullptr) return true;
    if(node->val < low || node->val > high) return false;
    return func(node->left, low, node->val) || func(node->right, node->val, high);
  }


  bool checkBST(TreeNode* node) {
    if(node == nullptr) return true;
    return func(node->left, -1e9, node->val) || func(node->right, node->val, 1e9);
  }
}


int main() {

}
