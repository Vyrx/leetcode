#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int max_depth[100001];
    int max_depth_without[100001];

    int maxDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        return max_depth[node->val] = 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        maxDepth(root); // get max depth rooted at cur node

        queue<pair<TreeNode*, int>> q; // node, depth
        priority_queue<pair<int, int>> maxDepth; // max depth, node that obtained it
        vector<int> curNodes;

        int curDepth = 0;
        q.push(make_pair(root, 0));
        while (true) {

            TreeNode* curNode = q.front().first;
            if (curNode->left != nullptr)
                q.push(make_pair(curNode->left, curDepth + 1));
            if (curNode->right != nullptr)
                q.push(make_pair(curNode->right, curDepth + 1));
            curNodes.push_back(curNode->val);
            maxDepth.push(make_pair(max_depth[curNode->val], curNode->val));
            q.pop();

            if (q.empty() || q.front().second != curDepth) {
                int curMax = curDepth + maxDepth.top().first;
                int curVal = maxDepth.top().second;
                maxDepth.pop();

                for (int it : curNodes) {
                    if (it != curVal)
                        max_depth_without[it] = curMax;
                    else {
                        if (!maxDepth.empty())
                            max_depth_without[it] = curDepth + maxDepth.top().first;
                        else
                            max_depth_without[it] = curDepth;
                    }
                }

                if (q.empty()) break;

                maxDepth = priority_queue<pair<int, int>>();
                curNodes = vector<int>();
                curDepth++;

            }
        }

        for (int it : queries) {
            ans.push_back(max_depth_without[it] - 1);
        }

        return ans;
    }
};