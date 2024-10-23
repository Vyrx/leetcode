#include <iostream>
#include<queue>
#include<utility>
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
    TreeNode* replaceValueInTree(TreeNode* root) {

        int cur_total_sum = root->val, next_total_sum = 0;
        int depth = 0;
        queue<pair<TreeNode*, int>> q; // [TreeNode, depth]
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            if (q.front().second != depth) {
                depth++;
                cur_total_sum = next_total_sum;
                next_total_sum = 0;
            }
            TreeNode* curNode = q.front().first;
            q.pop();
            curNode->val = cur_total_sum - curNode->val;

            if (curNode->left != nullptr && curNode->right != nullptr) {
                int sum = curNode->left->val + curNode->right->val;
                curNode->left->val = sum;
                curNode->right->val = sum;
                next_total_sum += sum;

                q.push(make_pair(curNode->left, depth + 1));
                q.push(make_pair(curNode->right, depth + 1));
            }
            else {
                if (curNode->left != nullptr) {
                    next_total_sum += curNode->left->val;
                    q.push(make_pair(curNode->left, depth + 1));
                }
                else if (curNode->right != nullptr) {
                    next_total_sum += curNode->right->val;
                    q.push(make_pair(curNode->right, depth + 1));
                }
            }

        }
        return root;
    }
};