#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = matrix.size(), n = matrix[0].size();

        bool evenNeg = true;
        int min_num = 100001;
        long long sum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] > 0) {
                    sum += matrix[i][j];
                    min_num = min(matrix[i][j], min_num);
                }
                else {
                    sum -= matrix[i][j];
                    min_num = min(-matrix[i][j], min_num);
                    evenNeg = !evenNeg;
                }
            }
        }

        return evenNeg ? sum : sum - 2 * min_num;
    }
};