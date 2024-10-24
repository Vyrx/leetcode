#include<iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isNodeEqual(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            if (node1 != nullptr || node2 != nullptr) return false;
            else return true;
        }
        if (node1->val != node2->val) return false;

        return (isNodeEqual(node1->left, node2->left) && isNodeEqual(node1->right, node2->right)) || (isNodeEqual(node1->left, node2->right) && isNodeEqual(node1->right, node2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isNodeEqual(root1, root2);
    }
};