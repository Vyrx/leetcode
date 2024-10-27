#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int sol = 0;
		for (int i = 0; i < matrix.size(); i++)
			sol += matrix[i][0];
		for (int j = 1; j < matrix[0].size(); j++)
			sol += matrix[0][j];

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) continue;

				matrix[i][j] = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
				sol += matrix[i][j];
			}
		}

		return sol;
	}
};

int main() {
	Solution S;
	vector<vector<int>> matrix({{1, 0, 1}, {1, 1, 0}, {1, 1, 0}} );
	S.countSquares(matrix);
}

