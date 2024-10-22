#include<iostream>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);

        queue<pair<TreeNode*, int>> q; // [value][level]
        priority_queue<long long> sum; 
        long long cur_sum;

        sum.push(root->val);
        if (root->left != nullptr) q.push(make_pair(root->left, 1));
        if (root->right != nullptr) q.push(make_pair(root->right, 1));

        int level = 1;
        while (!q.empty()) {
            cur_sum = 0;
            while (!q.empty() && q.front().second == level) {
                TreeNode* curNode = q.front().first;
                q.pop();
                cur_sum += curNode->val;
                if (curNode->left != nullptr) q.push(make_pair(curNode->left, level + 1));
                if (curNode->right != nullptr) q.push(make_pair(curNode->right, level + 1));
            }
            sum.push(cur_sum);
            level++;
        }

        if (k > level) return -1;

        for (int i = 0; i < k - 1; i++)
            sum.pop();

        return sum.top();
    }
};