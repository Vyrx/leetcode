#include<iostream>
#include<vector>
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
	vector<int> size;

	int sizeOfPerfectTree(TreeNode* node) {
		if (node == nullptr) return 0;

		int leftSize = sizeOfPerfectTree(node->left);
		int rightSize = sizeOfPerfectTree(node->right);

		if (leftSize == -1 || rightSize == -1 || leftSize != rightSize) return -1; // -1 -> not perfect

		size.push_back(1 + leftSize + rightSize);
		return 1 + leftSize + rightSize; 

	}

	int kthLargestPerfectSubtree(TreeNode* root, int k) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		sizeOfPerfectTree(root);

		sort(size.begin(), size.end(), greater<int>());
		if (k > size.size()) return -1;
		else return size[k - 1];
	}
};