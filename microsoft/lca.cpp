#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode* func(TreeNode* node, int left, int right) {
    if(node == nullptr) return nullptr;
    if(node->val == left || node->val == right) return node;
    TreeNode* leftSide = func(node->left, left, right);
    TreeNode* rightSide = func(node->right, left, right);
    if(leftSide != nullptr && rightSide != nullptr) return node;
    if(leftSide != nullptr) return lefft;
    if(rightSide != nullptr) return  right;
    return nullptr;
  }
  TreeNode* lca(TreeNode* node, int left, int right) {
    return func(node, left, right);
  }
};


int main() {

}
