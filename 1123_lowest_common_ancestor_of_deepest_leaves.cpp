#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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
	int find_max_depth(TreeNode* node, int cur_depth) {
		if (node == nullptr) return 0;
		return max(cur_depth, max(find_max_depth(node->left, cur_depth + 1), find_max_depth(node->right, cur_depth + 1)));
	}

	bool containDeepest(int max_depth, TreeNode* &ans, TreeNode* node, int cur_depth) {
		// if either left or right contain deepest = return true
		// if both left and right contain deepest also update ans

		if (node == nullptr) return false;
		if (cur_depth == max_depth) {
			if (ans == nullptr) ans = node;
			return true;
		}

		bool leftContain = containDeepest(max_depth, ans, node->left, cur_depth + 1);
		bool rightContain = containDeepest(max_depth, ans, node->right, cur_depth + 1);

		if (leftContain && rightContain) ans = node;

		return (leftContain || rightContain);
	}

	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		TreeNode* ans = nullptr;
		int max_depth = find_max_depth(root, 1);

		containDeepest(max_depth, ans, root, 1);

		return ans;
	}
};

void main() {
	Solution S;
	TreeNode* root = new TreeNode(3, new TreeNode(5), nullptr);
	S.lcaDeepestLeaves(root);
}